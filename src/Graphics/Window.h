#pragma once

#include <iostream>
#include <SDL.h>

namespace SmallGame
{
    namespace Graphics
    {
        class Window
        {
        private:
            int m_X, m_Y;
            int m_Width, m_Height;
            const char* m_Title;
            SDL_Window* m_Window;
            SDL_Renderer* m_Renderer;
            int m_WindowId;

            bool m_Closing;
            bool m_MouseFocusing;
            bool m_KeyFocusing;
            bool m_FullScreen;
            bool m_Showing;
            bool m_Minimized;
            bool m_Maximized;

            double m_MouseX, m_MouseY;

        public:
            static Window* INSTANCE;

        private:
            bool init();
        public:
            /* Create a default 800x450 no titled window at default location. */
            Window();
            /* Create a default 800x450 titled window at default location */
            Window(const char* title);
            /* Create a titled window at default location with customized size. */
            Window(const char* title, int width, int height);
            /* Create a titled window at a specific location with customized size. */
            Window(const char* title, int x, int y, int width, int height);
            ~Window();
            void handleEvent(SDL_Event& event);

            void getCursorPosition(double& x, double& y) const;
            inline int getWidth() const { return m_Width; }

            bool closed();
            void focus();
            void render();
            
        };
    }
}