#include <ImGuizmoC/ImSequencer.h>

#include <ImSequencer.h>

struct ImSequencerHandle_t: public ImSequencer::SequenceInterface
{
        ImSequencerHandle_t(ImSequencerParams params):
            _params(params)
        {}

        virtual int GetFrameMin() const 
        { 
            return _params.getFrameMin(_params.context, _params.contextSizeBytes); 
        }
        virtual int GetFrameMax() const 
        { 
            return _params.getFrameMax(_params.context, _params.contextSizeBytes);
        }
        virtual int GetItemCount() const 
        { 
            return _params.getItemCount(_params.context, _params.contextSizeBytes); 
        }
        virtual void BeginEdit(int index) {}
        virtual void EndEdit() {}
        virtual int GetItemTypeCount() const 
        { 
            return _params.getItemTypeCount(_params.context, _params.contextSizeBytes); 
        }
        virtual const char* GetItemTypeName(int typeIndex) const 
        { 
            return _params.getItemTypeName(_params.context, _params.contextSizeBytes,
                typeIndex);
        }
        virtual const char* GetItemLabel(int /*index*/) const { return ""; }
        virtual const char* GetCollapseFmt() const { return "%d Frames / %d entries"; }
        virtual void Get(int index, int** start, int** end, int* type, unsigned int* color) 
        {
            _params.getSequence(_params.context, _params.contextSizeBytes,
                index, start, end, type, color);            
        }
        virtual void Add(int type) {}
        virtual void Del(int index) {}
        virtual void Duplicate(int index) {}
        virtual void Copy() {}
        virtual void Paste() {}
        virtual size_t GetCustomHeight(int /*index*/) { return 0; }
        virtual void DoubleClick(int /*index*/) {}
        virtual void CustomDraw(int /*index*/, ImDrawList* /*draw_list*/, const ImRect& /*rc*/, const ImRect& /*legendRect*/, const ImRect& /*clippingRect*/, const ImRect& /*legendClippingRect*/) {}
        virtual void CustomDrawCompact(int /*index*/, ImDrawList* /*draw_list*/, const ImRect& /*rc*/, const ImRect& /*clippingRect*/) {}
    private:
        ImSequencerParams _params;
};

bool ImSequencer_createSequencer(ImSequencerParams params, ImSequencerHandle* sequencer)
{
    if (!sequencer)
        return false;

    *sequencer = new ImSequencerHandle_t(params);
    return true;
}

bool ImSequencer_destroySequencer(ImSequencerHandle sequencer)
{
    if (!sequencer)
        return false;
    delete sequencer;
    return true;
}

bool ImSequencer_draw(ImSequencerHandle sequencer, int* currentFrame, bool* expanded, int* selectedEntry, int* firstFrame, ImSequencerOptions sequencerOptions)
{
    if (!sequencer)
        return false;

    return ImSequencer::Sequencer(sequencer, currentFrame, expanded, selectedEntry, firstFrame, sequencerOptions);
}