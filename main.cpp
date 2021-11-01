#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides );


int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "House", NULL, NULL ); // "Polygon" is title of window
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity( ); // same as above comment

    GLfloat polygonVertices[] =
    {
        200, 240, 0, // 1 
        160, 240, 0, // 2
        160, 300, 0, // 3
        480, 300, 0,// 4
        480, 240, 0,// 5
        440, 240, 0,// 6
        440, 120, 0,// 7
        200, 120, 0,// 8
    };

    GLfloat door[] =
    {
        280, 120, 0, 
        280, 220, 0, // X, Y , Z Format
        360, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        360, 120, 0,
    };

    GLfloat window1[] =
    {
        220, 180, 0, 
        220, 220, 0, // X, Y , Z Format
        260, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        260, 180, 0,
    };

    GLfloat window2[] =
    {
        380, 180, 0, 
        380, 220, 0, // X, Y , Z Format
        420, 220, 0,// Follows on from above point (1) in CLOCK-WISE MANNER
        420, 180, 0,
    };

    GLfloat line1_left[] =
    {
        240, 180, 0,
        240, 220, 0
    };

    GLfloat line2_left[] =
    {
        220, 200, 0,
        260, 200, 0
    };
    
    GLfloat line1_right[] =
    {
        400, 180, 0,
        400, 220, 0
    };

    GLfloat line2_right[] =
    {
        380, 200, 0,
        420, 200, 0
    };
    

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // polygon drawing mode (GL_POINT, GL_LINE, GL_FILL)


    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );

        // render OpenGL here
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, polygonVertices ); 
        glDrawArrays( GL_POLYGON, 0, 8 ); // Number of points in polygon
        glDisableClientState( GL_VERTEX_ARRAY );

         // render OpenGL here 
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, door ); 
        glDrawArrays( GL_POLYGON, 0, 4 );// Number of points in polygon
        glDisableClientState( GL_VERTEX_ARRAY );

         // render OpenGL here 
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, window1 ); 
        glDrawArrays( GL_POLYGON, 0, 4 );// Number of points in polygon
        glDisableClientState( GL_VERTEX_ARRAY );

         // render OpenGL here 
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, window2 ); 
        glDrawArrays( GL_POLYGON, 0, 4 );// Number of points in polygon
        glDisableClientState( GL_VERTEX_ARRAY );

        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 3 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, line1_left ); // name of line
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_LINE_SMOOTH );

        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 3 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, line2_left ); // name of line
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_LINE_SMOOTH );

        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 3 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, line1_right ); // name of line
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_LINE_SMOOTH );

        // Render OpenGL here
        glEnable( GL_LINE_SMOOTH );
        // glEnable( GL_LINE_STIPPLE );
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 3 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, line2_right ); // name of line
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_LINE_SMOOTH );

        // render OpenGL here
        //drawCircle( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 120, 36 );
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;

}




// void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides )
// {
//     GLint numberOfVertices = numberOfSides + 1;
    
//     GLfloat doublePi = 2.0f * M_PI;
    
//     GLfloat circleVerticesX[numberOfVertices];
//     GLfloat circleVerticesY[numberOfVertices];
//     GLfloat circleVerticesZ[numberOfVertices];
    
//     //circleVerticesX[0] = x;
//     //circleVerticesY[0] = y;
//     //circleVerticesZ[0] = z;
    
//     for ( int i = 0; i < numberOfVertices; i++ )
//     {
//         circleVerticesX[i] = x + ( radius * cos( i * doublePi / numberOfSides ) );
//         circleVerticesY[i] = y + ( radius * sin( i * doublePi / numberOfSides ) );
//         circleVerticesZ[i] = z;
//     }
    
//     GLfloat allCircleVertices[numberOfVertices * 3];
    
//     for ( int i = 0; i < numberOfVertices; i++ )
//     {
//         allCircleVertices[i * 3] = circleVerticesX[i];
//         allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
//         allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
//     }
    
//     glEnableClientState( GL_VERTEX_ARRAY );
//     glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices );
//     glDrawArrays( GL_LINE_STRIP, 0, numberOfVertices );
//     glDisableClientState( GL_VERTEX_ARRAY );
// }
