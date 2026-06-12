#pragma once

#include "MainWindow.g.h"

#include <filesystem>

namespace winrt::TextEditor::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        std::filesystem::path _currentFile;
        bool _isDirty = false;

        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void Open_Click(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
		void Save_Click(IInspectable const&, Microsoft::UI::Xaml::RoutedEventArgs const&);
    };
}

namespace winrt::TextEditor::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
