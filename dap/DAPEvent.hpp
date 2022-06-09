#ifndef DAPEVENT_HPP
#define DAPEVENT_HPP

#include "dap.hpp"
#include "dap_exports.hpp"
#include <wx/event.h>

class WXDLLIMPEXP_DAP DAPEvent : public wxCommandEvent
{
protected:
    std::shared_ptr<dap::Any> m_object;

public:
    DAPEvent(wxEventType commandType = wxEVT_NULL, int winid = 0);
    DAPEvent(const DAPEvent& event);
    DAPEvent& operator=(const DAPEvent& src);
    virtual ~DAPEvent();

    void SetAnyObject(std::shared_ptr<dap::Any> any) { m_object = any; }
    wxEvent* Clone() const override;
    dap::Event* GetDapEvent() const;
    dap::Response* GetDapResponse() const;
};

typedef void (wxEvtHandler::*DAPEventFunction)(DAPEvent&);
#define DAPEventHandler(func) wxEVENT_HANDLER_CAST(DAPEventFunction, func)

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_INITIALIZE_RESPONSE, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_STACKTRACE_RESPONSE, DAPEvent);

wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_STOPPED_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_STOPPED_ON_ENTRY_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_PROCESS_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_EXITED_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_TERMINATED_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_INITIALIZED_EVENT, DAPEvent);
wxDECLARE_EXPORTED_EVENT(WXDLLIMPEXP_DAP, wxEVT_DAP_OUTPUT_EVENT, DAPEvent);

#endif // DAPEVENT_HPP
