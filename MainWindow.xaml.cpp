#include "pch.h"
#include "MainWindow.xaml.h"

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "FileService.h"

#include <winrt/Microsoft.UI.Text.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Text;

namespace winrt::TextEditor::implementation
{
    void MainWindow::Open_Click(
        IInspectable const&,
        RoutedEventArgs const&)
    {
        // Temporary test file
        std::filesystem::path path = exeDir / L"test.txt";

        if (!FileService::Exists(path))
        {
            return;
        }

        auto text = FileService::ReadAllText(path);

        EditorBox().Document().SetText(
            TextSetOptions::None,
            text);

        _currentFile = path;
        _isDirty = false;
    }

    void MainWindow::Save_Click(
        IInspectable const&,
        RoutedEventArgs const&)
    {
        winrt::hstring text;

        EditorBox().Document().GetText(
            TextGetOptions::None,
            text);

        if (_currentFile.empty())
        {
            _currentFile = exeDir / L"test.txt";
        }

        FileService::WriteAllText(
            _currentFile,
            text.c_str());

        _isDirty = false;
    }
}