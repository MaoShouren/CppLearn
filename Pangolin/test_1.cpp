#include <pangolin/pangolin.h>

int main() {
  // Create a window and OpenGL context
  pangolin::CreateWindowAndBind("Pangolin Demo", 640, 480);

  // Enable depth testing for 3D rendering
  glEnable(GL_DEPTH_TEST);

  // Define Projection and initial ModelView matrix
  pangolin::OpenGlRenderState s_cam(
    pangolin::ProjectionMatrix(640, 480, 420, 420, 320, 240, 0.1, 1000),
    pangolin::ModelViewLookAt(3, 3, 3, 0, 0, 0, pangolin::AxisY)
  );

  // Create a Viewport to handle display and interactive controls
  pangolin::Handler3D handler(s_cam);
  pangolin::View& d_cam = pangolin::CreateDisplay()
    .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f / 480.0f)
    .SetHandler(&handler);

  // Main event loop
  while (!pangolin::ShouldQuit()) {
    // Clear screen and activate view to render
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    d_cam.Activate(s_cam);

    // Render a rotating cube
    pangolin::glDrawColouredCube();

    // Swap buffers and process events
    pangolin::FinishFrame();
  }

  return 0;
}
