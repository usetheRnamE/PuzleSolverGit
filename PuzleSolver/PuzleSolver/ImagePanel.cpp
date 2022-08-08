#include "ImagePanel.h"

namespace GUI
{
    wxBEGIN_EVENT_TABLE(ImagePanel, wxPanel)
         // catch paint events
        EVT_PAINT(ImagePanel::paintEvent)
        //Size event
        EVT_SIZE(ImagePanel::OnSize)
        wxEND_EVENT_TABLE()

        ImagePanel::ImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
        wxPanel(parent)
    {
        image.LoadFile(file, format);
        w = -1;
        h = -1;
    }

    void ImagePanel::paintEvent(wxPaintEvent& evt)
    {
        wxPaintDC dc(this);
        render(dc);
    }
    void ImagePanel::paintNow()
    {
        wxClientDC dc(this);
        render(dc);
    }

    void ImagePanel::render(wxDC& dc)
    {
        int neww, newh;
        dc.GetSize(&neww, &newh);

        if (neww != w || newh != h)
        {
            resized = wxBitmap(image.Scale(neww, newh , wxIMAGE_QUALITY_HIGH));
            w = neww;
            h = newh;
            dc.DrawBitmap(resized, 0, 0, false);
        }
        else {
            dc.DrawBitmap(resized, 0, 0, false);
        }
    }

    void ImagePanel::OnSize(wxSizeEvent& event) {
        Refresh();

        event.Skip();
    }
}