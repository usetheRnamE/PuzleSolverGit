#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>

namespace GUI
{
    class ImagePanel : public wxPanel
    {
        wxImage image;
        wxBitmap resized;
        int w, h;

    public:
        ImagePanel(wxFrame* parent, wxString file, wxBitmapType format);

        void paintEvent(wxPaintEvent& evt);
        void paintNow();
        void OnSize(wxSizeEvent& event);
        void render(wxDC& dc);

        wxDECLARE_EVENT_TABLE();
    };
}

