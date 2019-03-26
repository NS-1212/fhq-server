#include "unit_test_jobs_pool.h"
#include <vector>
#include <md5.h>
#include <str.h>
#include <jobs_pool.h>


REGISTRY_UNIT_TEST(UnitTestJobsPool)

UnitTestJobsPool::UnitTestJobsPool()
    : UnitTestBase("UnitTestJobsPool") {
    //
}

// ----------------------------------------------------------------------

void UnitTestJobsPool::init() {
    // nothing
}

// ----------------------------------------------------------------------

class JobWaiterResult {
    public:
        JobWaiterResult() {
            m_nFinished = 0;
        }
        
        void onDone() {
            m_nFinished++;
        };

        void onFail(const std::string &sError) {
            Log::err("JobWaiterResult", "Failed job");
        };

        int finishedJobs() {
            return m_nFinished;
        };
    private:
        int m_nFinished;
};

// ----------------------------------------------------------------------

class JobAsyncWaiter : public JobAsync {
    public:
        JobAsyncWaiter(int n, int ms, JobWaiterResult* pJobWaiterResult) : JobAsync("job-example") { 
            m_nNumber = n;
            m_nMilliseconds = ms;
            m_pJobWaiterResult = pJobWaiterResult;
        };
        virtual bool run(const std::string &sWorkerId) {
            Log::info(sWorkerId, "begin job " + std::to_string(m_nNumber));
            std::this_thread::sleep_for(std::chrono::milliseconds(m_nMilliseconds));
            Log::info(sWorkerId, "end job  " + std::to_string(m_nNumber));
            m_pJobWaiterResult->onDone();
        }

    private:
        int m_nMilliseconds;
        JobWaiterResult* m_pJobWaiterResult;
        int m_nNumber;
};

// ----------------------------------------------------------------------

bool UnitTestJobsPool::run() {
    JobsPool::start();

    // TEST waitForDone
    int nCountJobs = 5;
    Log::info(TAG, "Check waitForDone...");
    JobWaiterResult *pJobWaiterResult = new JobWaiterResult();
    for(int i = 0; i < nCountJobs; i++) {
        JobsPool::addJobFast(new JobAsyncWaiter(i, 500, pJobWaiterResult));
    }

    JobsPool::waitForDone();
    if (pJobWaiterResult->finishedJobs() != nCountJobs) {
        Log::err(TAG, "Test waitForDone FAILED expected " + std::to_string(nCountJobs) + ", but got " + std::to_string(pJobWaiterResult->finishedJobs()));
        return false;
    }

    return true;
}
