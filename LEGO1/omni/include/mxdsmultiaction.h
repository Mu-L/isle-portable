#ifndef MXDSMULTIACTION_H
#define MXDSMULTIACTION_H

#include "mxdsaction.h"
#include "mxdsactionlist.h"

// VTABLE: LEGO1 0x100dcef0
// VTABLE: BETA10 0x101c28b0
// SIZE 0x9c
class MxDSMultiAction : public MxDSAction {
public:
	MxDSMultiAction();
	MxDSMultiAction(MxDSMultiAction& p_dsMultiAction);
	~MxDSMultiAction() override;

	void CopyFrom(MxDSMultiAction& p_dsMultiAction);
	MxDSMultiAction& operator=(MxDSMultiAction& p_dsMultiAction);

	// FUNCTION: LEGO1 0x100c9f50
	// FUNCTION: BETA10 0x1015b190
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x10101dbc
		return "MxDSMultiAction";
	}

	// FUNCTION: LEGO1 0x100c9f60
	// FUNCTION: BETA10 0x1015b1b0
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, MxDSMultiAction::ClassName()) || MxDSAction::IsA(p_name);
	}

	undefined4 VTable0x14() override;                            // vtable+0x14
	MxU32 GetSizeOnDisk() override;                              // vtable+0x18
	void Deserialize(MxU8*& p_source, MxS16 p_unk0x24) override; // vtable+0x1c
	void SetAtomId(MxAtomId p_atomId) override;                  // vtable+0x20
	MxDSAction* Clone() override;                                // vtable+0x2c
	void MergeFrom(MxDSAction& p_dsAction) override;             // vtable+0x30
	MxBool HasId(MxU32 p_objectId) override;                     // vtable+0x34
	void SetTimeStarted(MxLong p_timeStarted) override;          // vtable+0x38

	// FUNCTION: BETA10 0x1004e180
	MxDSActionList* GetActionList() const { return m_actionList; }

	// SYNTHETIC: LEGO1 0x100ca040
	// SYNTHETIC: BETA10 0x1015b210
	// MxDSMultiAction::`scalar deleting destructor'

protected:
	MxU32 m_sizeOnDisk;           // 0x94
	MxDSActionList* m_actionList; // 0x98
};

// SYNTHETIC: LEGO1 0x1004ad10
// SYNTHETIC: BETA10 0x1004dc50
// MxDSActionListCursor::`scalar deleting destructor'

// TEMPLATE: LEGO1 0x1004ad80
// TEMPLATE: BETA10 0x1004dca0
// MxListCursor<MxDSAction *>::~MxListCursor<MxDSAction *>

// SYNTHETIC: LEGO1 0x1004add0
// SYNTHETIC: BETA10 0x1004dd20
// MxListCursor<MxDSAction *>::`scalar deleting destructor'

// FUNCTION: LEGO1 0x1004ae40
// FUNCTION: BETA10 0x1004dd70
// MxDSActionListCursor::~MxDSActionListCursor

#endif // MXDSMULTIACTION_H
