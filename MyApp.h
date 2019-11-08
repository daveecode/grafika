#pragma once

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL.h>
#include <SDL_opengl.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

class CMyApp
{
public:
	CMyApp(void);
	~CMyApp(void);

	bool Init();
	void Clean();

	void Update();
	void Render();

	void KeyboardDown(SDL_KeyboardEvent&);
	void KeyboardUp(SDL_KeyboardEvent&);
	void MouseMove(SDL_MouseMotionEvent&);
	void MouseDown(SDL_MouseButtonEvent&);
	void MouseUp(SDL_MouseButtonEvent&);
	void MouseWheel(SDL_MouseWheelEvent&);
	void Resize(int, int);
protected:
	// seg�df�ggv�nyek

	void CreateCircle1(const float& r);
	void CreateCircle2(const float& r, const float& position);
	void drawCircle();
	void drawCircle2();

	glm::vec3 GetPos(float u, float v);

	// shaderekhez sz�ks�ges v�ltoz�k
	GLuint m_programID; // shaderek programja

	// OpenGL-es dolgok
	GLuint cylinder_VAO; // vertex array object er�forr�s azonos�t�
	GLuint cylinder_VBO; // vertex buffer object er�forr�s azonos�t�
	GLuint m_ibID;  // index buffer object er�forr�s azonos�t�
	GLuint circle_VAO;
	GLuint circle_VBO;
	GLuint circle2_VAO;
	GLuint circle2_VBO;

	// transzform�ci�s m�trixok
	glm::mat4 m_matWorld;
	glm::mat4 m_matView;
	glm::mat4 m_matProj;

	// m�trixok helye a shaderekben
	GLuint	m_loc_mvp; // a h�rom m�trixunk szorzat�t adjuk �t a hat�konys�g �rdek�ben

	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 c;
	};

	// NxM darab n�gysz�ggel k�zel�tj�k a parametrikus fel�let�nket => (N+1)x(M+1) pontban kell ki�rt�kelni
	static const int N	= 20;
	static const int M	= 10;
};

