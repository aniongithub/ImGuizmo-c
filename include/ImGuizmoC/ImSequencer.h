#pragma once

#include "ImGuizmo.h"

enum ImSequencerOptions_t
{
    IMSEQUENCER_EDIT_NONE = 0,
    IMSEQUENCER_EDIT_STARTEND = 1 << 1,
    IMSEQUENCER_CHANGE_FRAME = 1 << 3,
    IMSEQUENCER_ADD = 1 << 4,
    IMSEQUENCER_DEL = 1 << 5,
    IMSEQUENCER_COPYPASTE = 1 << 6,
    IMSEQUENCER_EDIT_ALL = IMSEQUENCER_EDIT_STARTEND | IMSEQUENCER_CHANGE_FRAME
};
typedef enum ImSequencerOptions_t ImSequencerOptions;

typedef int (*ImSequencer_GetIntCallback)(void* context, size_t contextSizeBytes);

typedef void (*ImSequencer_FocusChangedCallback)(void* context, size_t contextSizeBytes, bool focused);
typedef void (*ImSequencer_BeginEditCallback)(void* context, size_t contextSizeBytes, int index);
typedef void (*ImSequencer_EndEditCallback)(void* context, size_t contextSizeBytes);
typedef const char* (*ImSequencer_GetItemTypeNameCallback)(void* context, size_t contextSizeBytes, int typeIndex);
typedef const char* (*ImSequencer_GetItemLabelCallback)(void* context, size_t contextSizeBytes, int index);
typedef const char* (*ImSequencer_GetCollapseFmtCallback)(void* context, size_t contextSizeBytes);

typedef void (*ImSequencer_GetSequenceCallback)(void* context, size_t contextSizeBytes, int index, int** start, int** end, int* type, unsigned int* color);
typedef void (*ImSequencer_AddSequenceCallback)(void* context, size_t contextSizeBytes, int type);
typedef void (*ImSequencer_DelSequenceCallback)(void* context, size_t contextSizeBytes, int index);
typedef void (*ImSequencer_DuplicateSequenceCallback)(void* context, size_t contextSizeBytes, int index);

typedef void (*ImSequencer_CopyCallback)(void* context, size_t contextSizeBytes);
typedef void (*ImSequencer_PasteCallback)(void* context, size_t contextSizeBytes);

typedef size_t (*ImSequencer_GetCustomHeightCallback)(void* context, size_t contextSizeBytes, int index);
typedef void (*ImSequencer_DoubleClickCallback)(void* context, size_t contextSizeBytes, int index);
typedef void (*ImSequencer_CustomDrawCallback)(void* context, size_t contextSizeBytes, int index, ImDrawList* draw_list, ImRect rc, ImRect legendRect, ImRect clippingRect, ImRect legendClippingRect);
typedef void (*ImSequencer_CustomDrawCompactCallback)(void* context, size_t contextSizeBytes, int index, ImDrawList* draw_list, ImRect rc, ImRect clippingRect);

struct ImSequencerParams_t
{
    void* context;
    size_t contextSizeBytes;

    ImSequencer_GetIntCallback getFrameMin;
    ImSequencer_GetIntCallback getFrameMax;
    ImSequencer_GetIntCallback getItemCount;

    ImSequencer_BeginEditCallback beginEdit;
    ImSequencer_EndEditCallback endEdit;

    ImSequencer_GetIntCallback getItemTypeCount;
    ImSequencer_GetItemTypeNameCallback getItemTypeName;
    ImSequencer_GetItemLabelCallback getItemLabel;
    ImSequencer_GetCollapseFmtCallback GetCollapseFmtCallback;

    ImSequencer_GetSequenceCallback getSequence;
    ImSequencer_AddSequenceCallback addSequence;
    ImSequencer_DelSequenceCallback delSequence;
    ImSequencer_DuplicateSequenceCallback duplicateSequence;

    ImSequencer_CopyCallback copy;
    ImSequencer_PasteCallback paste;

    ImSequencer_GetCustomHeightCallback getCustomHeight;
    ImSequencer_DoubleClickCallback doubleClick;
    
    ImSequencer_CustomDrawCallback customDraw;
    ImSequencer_CustomDrawCompactCallback customDrawCompact;
};

typedef struct ImSequencerParams_t ImSequencerParams;

struct ImSequencerHandle_t;
typedef struct ImSequencerHandle_t* ImSequencerHandle;

bool ImSequencer_createSequencer(ImSequencerParams params, ImSequencerHandle* sequencer);
bool ImSequencer_destroySequencer(ImSequencerHandle sequencer);
bool ImSequencer_draw(ImSequencerHandle sequencer, int* currentFrame, bool* expanded, int* selectedEntry, int* firstFrame, ImSequencerOptions sequencerOptions);