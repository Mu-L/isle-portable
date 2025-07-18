#ifndef LEGOPARTPRESENTER_H
#define LEGOPARTPRESENTER_H

#include "lego1_export.h"
#include "legonamedpartlist.h"
#include "mxmediapresenter.h"
#include "viewmanager/viewlodlist.h"

// VTABLE: LEGO1 0x100d4df0
// SIZE 0x54
class LegoPartPresenter : public MxMediaPresenter {
public:
	LegoPartPresenter() { Reset(); }

	// FUNCTION: LEGO1 0x10067300
	~LegoPartPresenter() override { Destroy(TRUE); }

	// FUNCTION: LEGO1 0x1000cf60
	void Destroy() override { Destroy(FALSE); } // vtable+0x38

	// FUNCTION: BETA10 0x100a75d0
	static const char* HandlerClassName()
	{
		// STRING: LEGO1 0x100f05d8
		return "LegoPartPresenter";
	}

	// FUNCTION: LEGO1 0x1000cf70
	// FUNCTION: BETA10 0x100a75a0
	const char* ClassName() const override // vtable+0x0c
	{
		return HandlerClassName();
	}

	// FUNCTION: LEGO1 0x1000cf80
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, LegoPartPresenter::ClassName()) || MxMediaPresenter::IsA(p_name);
	}

	void ReadyTickle() override;      // vtable+0x18
	MxResult AddToManager() override; // vtable+0x34

	LEGO1_EXPORT static void configureLegoPartPresenter(MxS32, MxS32);

	// SYNTHETIC: LEGO1 0x1000d060
	// LegoPartPresenter::`scalar deleting destructor'

	void Reset() { m_parts = NULL; }

	MxResult Read(MxDSChunk& p_chunk);
	void Store();

	static void Release()
	{
		for (auto* lodList : g_lodLists) {
			lodList->Release();
		}

		g_lodLists.clear();
	}

private:
	void Destroy(MxBool p_fromDestructor);

	LegoNamedPartList* m_parts; // 0x50

	static vector<ViewLODList*> g_lodLists;
};

#endif // LEGOPARTPRESENTER_H
