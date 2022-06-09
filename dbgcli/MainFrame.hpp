#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "UI.hpp"
#include "dap/Client.hpp"
#include <vector>
#include <wx/filename.h>

class MainFrame : public MainFrameBase
{
    dap::Client m_client;
    wxFileName m_current_file_loaded;
    std::vector<wxStyledTextCtrl*> m_ctrls;

public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

protected:
    void InitializeClient();
    void AddLog(const wxString& log);
    void LoadFile(const wxString& filepath, int line_number);

protected:
    void OnConnectUI(wxUpdateUIEvent& event) override;
    void OnNextUI(wxUpdateUIEvent& event) override;
    void OnStepInUI(wxUpdateUIEvent& event) override;
    void OnStepOutUI(wxUpdateUIEvent& event) override;
    void OnConnect(wxCommandEvent& event) override;
    void OnNext(wxCommandEvent& event) override;
    void OnStepIn(wxCommandEvent& event) override;
    void OnStepOut(wxCommandEvent& event) override;

    /// Dap events
    void OnStopped(DAPEvent& event);
    void OnStoppedOnFirstEntry(DAPEvent& event);
    void OnStackTrace(DAPEvent& event);
    void OnInitialized(DAPEvent& event);
    void OnExited(DAPEvent& event);
    void OnTerminated(DAPEvent& event);
    void OnOutput(DAPEvent& event);
};
#endif // MAINFRAME_HPP
