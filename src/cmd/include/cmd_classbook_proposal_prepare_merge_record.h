#ifndef CMD_CLASSBOOK_PROPOSAL_PREPARE_MERGE_RECORD_H
#define CMD_CLASSBOOK_PROPOSAL_PREPARE_MERGE_RECORD_H

#include <iserver.h>

class CmdClassbookProposalPrepareMergeRecordHandler : public ICmdHandler {

    public:
        CmdClassbookProposalPrepareMergeRecordHandler();
        virtual std::string cmd();
        virtual bool accessUnauthorized();
        virtual bool accessUser();
        virtual bool accessTester();
        virtual bool accessAdmin();
        virtual const std::vector<CmdInputDef> &inputs();
        virtual QString description();
        virtual QStringList errors();
        virtual void handle(QWebSocket *pClient, IWebSocketServer *pWebSocketServer, QString m, QJsonObject obj);

    private:
        QString TAG;
        std::vector<CmdInputDef> m_vInputs;
};

#endif // CMD_CLASSBOOK_PROPOSAL_PREPARE_MERGE_RECORD_H
