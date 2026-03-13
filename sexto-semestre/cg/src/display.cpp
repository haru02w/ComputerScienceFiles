#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <ctime>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/glut.h>
#include <sys/time.h>

typedef struct rotation {
  double a; // Rotação em torno do eixo X
  double b; // Rotação em torno do eixo Y
  double c; // Rotação em torno do eixo Z
} Rotate;

using namespace std;

Rotate rotate = {0.0, 0.0, 0.0};

GLfloat AspectRatio;
GLfloat AngY;
bool fazCalculoPonto;

GLuint bola;
GLuint maca;
GLfloat AnguloDeVisao;
GLfloat Obs[3];
GLfloat Alvo[3];

int isDragging = 0; // Controle para verificar se o mouse está arrastando
int lastMouseX = 0; // Armazenar a última posição X do mouse
int lastMouseY = 0; // Armazenar a última posição Y do mouse

// Função para carregar a textura
void loadTexture(const char *filename, GLuint *textureID) {
  int width, height, nrChannels;
  unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

  if (data) {
    GLenum format;
    if (nrChannels == 1)
      format = GL_RED;
    else if (nrChannels == 3)
      format = GL_RGB;
    else if (nrChannels == 4)
      format = GL_RGBA;
    else {
      printf("Formato de imagem não suportado: %d canais\n", nrChannels);
      stbi_image_free(data);
      return;
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);

    // Parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    printf("Textura carregada com sucesso: %s (%d x %d)\n", filename, width,
           height);
  } else {
    printf("Falha ao carregar a textura: %s\n", filename);
  }
  stbi_image_free(data); // Libera a memória
}

// Função para capturar o clique do mouse
void mouseClick(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      // Inicia o arraste
      isDragging = 1;
      lastMouseX = x;
      lastMouseY = y;
    } else if (state == GLUT_UP) {
      // Para o arraste
      isDragging = 0;
    }
  }
}

// Função para capturar o movimento do mouse enquanto o botão está pressionado
void mouseMotion(int x, int y) {
  if (isDragging) {
    // Calcula a diferença de movimento
    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    // Atualiza as rotações com base no movimento do mouse
    rotate.a += dy * 0.1; // Rotaciona em torno do eixo X
    rotate.b += dx * 0.1; // Rotaciona em torno do eixo Y

    // Atualiza as últimas posições do mouse
    lastMouseX = x;
    lastMouseY = y;

    // Força a função display a ser chamada novamente
    glutPostRedisplay();
  }
}

void init(void) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundo de tela preto

  glShadeModel(GL_FLAT);
  // glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  Obs[0] = 0;
  Obs[1] = 3;
  Obs[2] = 3;
  Alvo[0] = 0;
  Alvo[1] = 0;
  Alvo[2] = -1;
  AnguloDeVisao = 80;
  AngY = 0;
  fazCalculoPonto = false;

  loadTexture("../assets/soccer_ball.jpg", &bola); // Carregar textura da maçã
  loadTexture("../assets/maca.jpg", &maca);
}

void PosicUser() {
  // Set the clipping volume
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(AnguloDeVisao, AspectRatio, 0.01, 200);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Obs[0], Obs[1], Obs[2], Alvo[0], Alvo[1], Alvo[2], 0.0f, 1.0f,
            0.0f);
}

void reshape(int w, int h) {

  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if (h == 0)
    h = 1;

  // Ajusta a relaÃ§Ã£o entre largura e altura para evitar distorÃ§Ã£o na
  // imagem. Veja funÃ§Ã£o "PosicUser".
  AspectRatio = 1.0f * w / h;

  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  //  Set the viewport to be the entire window
  glViewport(0, 0, w, h);

  PosicUser();
}
// Função para desenhar o caule da maçã
void drawStem() {
  glColor3f(0.4, 0.2, 0.0); // Cor do caule
  glPushMatrix();
  glTranslatef(0.0, 0.6, 0.0);   // Posição do caule
  glRotatef(-90, 1.0, 0.0, 0.0); // Rotacionar para a orientação correta
  GLUquadric *quad = gluNewQuadric();
  gluCylinder(quad, 0.05, 0.05, 0.3, 30, 30); // Desenha um cilindro como caule
  gluDeleteQuadric(quad);
  glPopMatrix();
}

void DesenhaCenario(bool desenha) {
  //- Uma esfera de cor sólida
  glPushMatrix();
  glTranslatef(-4.0, 0.0, 0.0); // Move to the side
  glColor3f(0.0, 1.0, 0.0);     // Green color
  glutSolidSphere(1.0, 50, 50);
  glPopMatrix();

  // - Uma esfera em wireframe
  glPushMatrix();
  glTranslatef(-2.0, 0.0, 0.0); // Move to the side
  glColor3f(0.0, 0.0, 1.0);     // Green color
  glutWireSphere(1.0, 50, 50);
  glPopMatrix();

  // - Uma bola (pode definir o esporte que desejar)
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, bola);
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0); // Define a cor como vermelha para usar a textura
  GLUquadric *quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE); // Habilitar textura na quadric

  glTranslatef(0.0, 0.0, 0.0);  // Move to the side
  gluSphere(quad, 1.0, 50, 50); // Desenha uma bola texturizada

  gluDeleteQuadric(quad);
  glPopMatrix();

  // - Uma maça na cor vermelha ou verde ou amarela ou pink, em que a cor deverá
  // ser aplicada a respectiva textura correspondente
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, maca);

  glPushMatrix();

  // Desenha uma maçã com formato mais realista usando uma malha
  glColor3f(1.0, 1.0, 1.0); // Define a cor como branca para usar a textura
  quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE); // Habilitar textura na quadric

  // Formato mais achatado
  glTranslatef(2.0, 0.0, 0.0);  // Move to the side
  glScalef(0.8, 0.9, 0.8);      // achatamento para simular a maçã
  gluSphere(quad, 1.0, 50, 50); // Desenha uma esfera texturizada como maçã

  gluDeleteQuadric(quad);

  glPopMatrix();
  // drawStem(); // Desenha o caule da maçã
}

// **********************************************************************
//  void display( void )
//
// **********************************************************************

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  PosicUser();

  glRotatef(rotate.a, 1.0, 0.0, 0.0); // Rotaciona a cena para visualizar melhor
  glRotatef(rotate.b, 0.0, 1.0, 0.0); // Rotaciona a maçã
  //
  DesenhaCenario(true);

  glutSwapBuffers();
}

// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:   // Termina o programa qdo
    exit(0); // a tecla ESC for pressionada
    break;
  case ' ':
    fazCalculoPonto = true;
    break;
  case 'a':
  case 'A':
    AngY += 5;
    break;
  default:
    break;
  }
}

void arrow_keys(int a_keys, int x, int y) {
  switch (a_keys) {
  case GLUT_KEY_UP:   // When Up Arrow Is Pressed...
    glutFullScreen(); // Go Into Full Screen Mode
    break;
  case GLUT_KEY_DOWN: // When Down Arrow Is Pressed...
    glutInitWindowSize(700, 500);
    break;
  default:
    break;
  }
}

void update(int value) {
  // Força a função display a ser chamada novamente
  glutPostRedisplay();

  // Configura para chamar novamente a função update após 16 ms (~60fps)
  glutTimerFunc(16, update, 0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(
      GLUT_DOUBLE | GLUT_DEPTH |
      GLUT_RGB); // | GLUT_STEREO);// | GLUT_DOUBLE | GLUT_RGBA );
  // glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_STEREO);// | GLUT_DOUBLE
  // | GLUT_RGBA );

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(700, 500);
  glutCreateWindow("ComputaÃ§Ã£o GrÃ¡fica - TransformaÃ§Ãµes HierÃ¡rquicas 3D");

  init();

  // Configura a função de mouse
  glutMouseFunc(mouseClick);
  glutMotionFunc(mouseMotion);

  // Configura o timer para atualizar a animação
  glutTimerFunc(16, update, 0); // Chama "update" a cada 16ms (~60fps)

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrow_keys);
  glutIdleFunc(display);

  glutMainLoop();
  return 0;
}
