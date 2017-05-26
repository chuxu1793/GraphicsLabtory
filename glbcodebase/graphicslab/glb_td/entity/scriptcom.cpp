//------------------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2017. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2017/05/25
// Brief: Script component update entity's AI
//------------------------------------------------------------
#include "scriptcom.h"

#include <memory>

#include "../pyscript/pyscriptmgr.h"

namespace entity {

ScriptCom::ScriptCom(const char* file)
: Component(CT_SCRIPT) {
    int32_t len = strlen(file);
    len = (len > kScriptFileNameMaxLen - 1) ? (kScriptFileNameMaxLen - 1) : len;
    memcpy(m_ScriptFile, file, len);
    m_ScriptFile[len] = '\0';
}

ScriptCom::~ScriptCom() {
}

void ScriptCom::Update(float dt) {
    pyscript::PyScriptMgr::RunScript(m_ScriptFile);
}

};  // namespace entity