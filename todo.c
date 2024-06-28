#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <leif/leif.h>

#define WIN_MARGIN 20.0f

static int winw = 1280, winh = 720;
static LfFont titlefont;

int main() {
  glfwInit();

  GLFWwindow *window = glfwCreateWindow(winw, winh, "Todo", NULL, NULL);

  glfwMakeContextCurrent(window);

  lf_init_glfw(winw, winh, window);

  LfTheme theme = lf_get_theme();
  theme.div_props.color = LF_NO_COLOR;
  lf_set_theme(theme);

  titlefont = lf_load_font("./fonts/inter-bold.ttf", 40);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0);

    lf_begin();
    lf_div_begin(((vec2s){WIN_MARGIN, WIN_MARGIN}),
                 ((vec2s){winw - WIN_MARGIN * 2.0f, winh - WIN_MARGIN * 2.0f}),
                 true);

    lf_push_font(&titlefont);
    lf_text("Get Done:");
    lf_pop_font();

    lf_div_end();
    lf_end();

    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  lf_free_font(&titlefont);

  glfwDestroyWindow(window);
  glfwTerminate();
}
