//
#include "Window.h"

namespace SmallGame
{
    namespace Graphics
    {
        bool Window::init()
        {
            // where is video init?
            m_Window = SDL_CreateWindow(m_Title, m_X, m_Y, m_Width, m_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
            if (m_Window == NULL)
            {
                std::cout << "Window->init() -> SDL_CreateWindow(const char* int, int, int, int, Uint32) failed: " << SDL_GetError() << std::endl;
                return false;
            }

            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (m_Renderer == NULL)
            {
                std::cout << "Window->init() -> SDL_CreateRenderer(SDL_Window*, int, Uint32) failed: " << SDL_GetError() << std::endl;
                SDL_DestroyWindow(m_Window);
                return false;
            }

            m_MouseFocusing = true;
            m_KeyFocusing = true;
            m_WindowId = SDL_GetWindowID(m_Window);
            m_Showing = true;
            //SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            return true;
        }

        Window::Window()
            : Window("")
        {
        }

        Window::Window(const char * title)
            : Window(title, 800, 450)
        {
        }

        Window::Window(const char* title, int width, int height)
            : Window(title, 50, 50, width, height)
        {
        }

        Window::Window(const char* title, int x, int y, int width, int height)
            : m_Title(title), m_X(x), m_Y(y), m_Width(width), m_Height(height)
        {
            if (!init()) { SDL_Quit(); }
            // else;
            m_Closing = false;

        }

        Window::~Window()
        {
            delete m_Title;
            SDL_DestroyRenderer(m_Renderer);
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
        }

        void Window::handleEvent(SDL_Event& event)
        {
            if (event.type == SDL_WINDOWEVENT && event.window.windowID == m_WindowId)
            {
                bool flag_UpdateCaption = false;
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_SHOWN:
                        m_Showing = true;
                        break;
                    case SDL_WINDOWEVENT_HIDDEN:
                        m_Showing = false;
                        break;
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        m_Width = event.window.data1;
                        m_Height = event.window.data2;
                        SDL_RenderPresent(m_Renderer);
                        break;
                    case SDL_WINDOWEVENT_EXPOSED:
                        SDL_RenderPresent(m_Renderer);
                        break;
                    case SDL_WINDOWEVENT_ENTER:
                        m_MouseFocusing = true;
                        flag_UpdateCaption = true;
                        break;
                    case SDL_WINDOWEVENT_LEAVE:
                        m_MouseFocusing = false;
                        flag_UpdateCaption = true;
                        break;
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        m_KeyFocusing = true;
                        flag_UpdateCaption = true;
                        break;
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        m_KeyFocusing = false;
                        flag_UpdateCaption = false;
                        break;
                    case SDL_WINDOWEVENT_MINIMIZED:
                        m_Minimized = true;
                        break;
                    case SDL_WINDOWEVENT_MAXIMIZED:
                        m_Minimized = false;
                        break;
                    case SDL_WINDOWEVENT_RESTORED:
                        m_Minimized = false;
                        break;
                    case SDL_WINDOWEVENT_CLOSE:
                        SDL_HideWindow(m_Window);
                        break;
                    default:
                        std::cout << "Window->handleEvent(SDL_Event&) -> Event type not supported: " << int(event.window.event) << std::endl;
                        break;
                }
                if (flag_UpdateCaption)
                {
                    //SDL_SetWindowTitle(m_Window, "");
                }
            }
        }

        bool Window::closed()
        {
            return m_Closing;
        }

        void Window::focus()
        {
            if (!m_Showing)
            {
                SDL_ShowWindow(m_Window);
            }
            SDL_RaiseWindow(m_Window);
        }

        void Window::render()
        {
            if (!m_Minimized)
            {
                SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(m_Renderer);
                SDL_RenderPresent(m_Renderer);
            }
        }
    }
}