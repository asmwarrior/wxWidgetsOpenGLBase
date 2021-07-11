#pragma once

#ifndef GL_PANE_H
#define GL_PANE_H


class Shader;
class Object;
// #include "Shader.h"
// #include "Object.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>

// #include <glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

#include <chrono>

class GLPane : public wxGLCanvas
{
public:
    GLPane(wxFrame *parent, int *args);
    virtual ~GLPane();

    int getWidth();
    int getHeight();

private:
    wxGLContext *m_pContext;
    Object *m_pObj;
    Shader *m_pShader;
    int m_frameCnt;
    float m_angle;
    glm::mat4 m_proj;
    
    std::chrono::time_point<std::chrono::system_clock> m_tStart;

    void prepareGLObjects();

    void render(wxPaintEvent &evt);
    void resized(wxSizeEvent &evt);

    void mouseMoved(wxMouseEvent &evt);
    void mouseDown(wxMouseEvent &evt);
    void mouseWheelMoved(wxMouseEvent &evt);
    void mouseReleased(wxMouseEvent &evt);
    void rightClick(wxMouseEvent &evt);
    void mouseLeftWindow(wxMouseEvent &evt);
    void keyPressed(wxKeyEvent &evt);
    void keyReleased(wxKeyEvent &evt);

    DECLARE_EVENT_TABLE()
};

#endif // !GL_PANE_H
