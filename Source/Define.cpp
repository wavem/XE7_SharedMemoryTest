//---------------------------------------------------------------------------

#pragma hdrstop

#include "Define.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)




__fastcall CSharedMemory::CSharedMemory() {
	m_handle = NULL;
    m_strName = L"";
    m_nMemSize = 0;
    m_Ptr = NULL;
}
//---------------------------------------------------------------------------

bool __fastcall CSharedMemory::Create() {
	m_handle = OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, m_strName.c_str());
    if (m_handle != NULL) {
    	FormMain->PrintMsg(L"It is already existed.");
        return true;
    }

    m_handle = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, m_nMemSize, m_strName.c_str());
    if (m_handle == NULL) {
    	FormMain->PrintMsg(L"Failed to create SM.");
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------

bool __fastcall CSharedMemory::Attach() {
	if (m_Ptr != NULL) {
    	FormMain->PrintMsg(L"You already attached to SM.");
        return false;
    }
    m_Ptr = MapViewOfFile(m_handle, FILE_MAP_ALL_ACCESS, 0, 0, m_nMemSize);
    if (m_Ptr == NULL) {
    	FormMain->PrintMsg(L"Failed to create SM.");
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------
