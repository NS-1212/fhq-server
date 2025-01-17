/**********************************************************************************
 *          Project
 *    __ _
 *   / _| |__   __ _       ___  ___ _ ____   _____ _ __
 *  | |_| '_ \ / _` | ___ / __|/ _ \ '__\ \ / / _ \ '__|
 *  |  _| | | | (_| ||___|\__ \  __/ |   \ V /  __/ |
 *  |_| |_| |_|\__, |     |___/\___|_|    \_/ \___|_|
 *                |_|
 *
 * Copyright (c) 2011-2024 FreeHackQuest <freehackquest@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ***********************************************************************************/

#pragma once

#include <cmd_handlers.h>

class CmdHandlerGameCreate : public CmdHandlerBase {

public:
  CmdHandlerGameCreate();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGameDelete : public CmdHandlerBase {

public:
  CmdHandlerGameDelete();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGameExport : public CmdHandlerBase {
public:
  CmdHandlerGameExport();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGameImport : public CmdHandlerBase {

public:
  CmdHandlerGameImport();
  virtual void handle(ModelRequest *pRequest);
};

// depreacted

class CmdHandlerGameInfo : public CmdHandlerBase {

public:
  CmdHandlerGameInfo();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGamesInfo : public CmdHandlerBase {

public:
  CmdHandlerGamesInfo();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGameUpdate : public CmdHandlerBase {

public:
  CmdHandlerGameUpdate();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGameUpdateLogo : public CmdHandlerBase {

public:
  CmdHandlerGameUpdateLogo();
  virtual void handle(ModelRequest *pRequest);
};

class CmdHandlerGamesList : public CmdHandlerBase {

public:
  CmdHandlerGamesList();
  virtual void handle(ModelRequest *pRequest);
};
