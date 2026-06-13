#pragma once

#include "MainWindow.g.h"

#include <filesystem>

#include <Windows.h>
#include <winrt/Microsoft.UI.Text.h>
#include <winrt/Windows.Storage.Pickers.h>
#include <shobjidl_core.h>

namespace winrt::TextEditor::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        std::filesystem::path _currentFile;
        bool _isDirty = false;

        std::filesystem::path exeDir;

        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            wchar_t buffer[MAX_PATH];
            GetModuleFileNameW(nullptr, buffer, MAX_PATH);

            std::filesystem::path exePath(buffer);
            exeDir = exePath.parent_path();
        }

        void Open_Click(winrt::Windows::Foundation::IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
		void Save_Click(winrt::Windows::Foundation::IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
    };
}

namespace winrt::TextEditor::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
