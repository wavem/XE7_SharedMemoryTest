//---------------------------------------------------------------------------

#ifndef DefineH
#define DefineH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>


typedef struct st_Protocol {
	BYTE Data;
} Protocol;


class CSharedMemory {
private:

public:
	__fastcall CSharedMemory();
    __fastcall ~CSharedMemory();

// Member Variables
	HANDLE m_handle;
    UnicodeString m_strName;
    __int64 m_nMemSize;
    void* m_Ptr;


// Member Functions
	bool __fastcall Create();
    bool __fastcall Attach();



};

//---------------------------------------------------------------------------
#endif
