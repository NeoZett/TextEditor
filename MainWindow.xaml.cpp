#include "pch.h"
#include "MainWindow.xaml.h"

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "FileService.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::TextEditor::implementation
{
    void MainWindow::Open_Click(
        IInspectable const&,
        Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
    }

    void MainWindow::Save_Click(
        IInspectable const&,
        Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
    }
}