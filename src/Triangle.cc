#include "Triangle.h"

namespace Triangle
{
        void Triangle::shaderCodeReader(std::string &shaderCode, const std::string &file_path)
    {
        // Read the Vertex Shader code from the file
        std::string VertexShaderCode;
        std::ifstream VertexShaderStream(file_path, std::ios::in);
        if (!VertexShaderStream.is_open())
        {
            throw std::runtime_error("Could not open/find shader code files.");
        }
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        shaderCode = sstr.str();
        VertexShaderStream.close();
        // std::cout << "Shader code read successfully: " << std::endl << shaderCode << std::endl;
    }

    Triangle::Triangle(/* args */)
    {
        std::string vertexShaderCodePath{"/Users/amirnourinia/Developer/openGL/src/shaders/triangleVertexShader.glsl"};
        std::string framgentShaderCodePath{"/Users/amirnourinia/Developer/openGL/src/shaders/triangleFramgmentShader.glsl"};
        shaderCodeReader(vertexShaderSourceCode, vertexShaderCodePath);
        shaderCodeReader(fragmentShaderSourceCode, framgentShaderCodePath);
    }

    Triangle::~Triangle()
    {
        cleanup();
    }

    void Triangle::initWindow()
    {
        window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            throw std::runtime_error("Error creating window.");
        }
        // set context to current window.
        glfwMakeContextCurrent(window);
    }
    void Triangle::initGLFW()
    {
        if (glfwInit() == GLFW_FALSE)
            throw std::runtime_error("Error creating initializing the GLEW.");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        // On macos we need this check
        if (__APPLE__)
        {
            print::printLine("Platform Detected: MacOS");
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        }
    }

    void Triangle::setWindowAttributes()
    {

        // Set viewport.
        glViewport(0, 0, 800, 600);

        // fix handles:  here, resizing callback
        glfwSetFramebufferSizeCallback(window, windowHandling::framebuffer_size_callback);
    }
    void Triangle::configureObject(){
        
        // Generate vertex array object to wrap the configurations.
        glGenVertexArrays(1,&vao);
        glBindVertexArray(vao);
        upLoadVerticies();
        setUpMemoryLayout();
        // Unbind the vao, bind it when you want to use it.
        // glBindVertexArray(0);
    }

    // Load the verticies onto GPU
    void Triangle::upLoadVerticies()
    {
        // Generate buffer id;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, verticies.sizeInBytes, verticies.data, GL_STATIC_DRAW);
    }

    // Setup shaders.
    void Triangle::setUpShaders()
    {
        uint vertexShader;
        uint fragmentShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char *vssc = vertexShaderSourceCode.c_str();
        const char *fssc = fragmentShaderSourceCode.c_str();
        glShaderSource(vertexShader, 1, &vssc, NULL);
        glShaderSource(fragmentShader, 1, &fssc, NULL);

        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);

        int vstatus, fstatus, lstatus;
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&vstatus);
        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&fstatus);
        if( vstatus == GL_TRUE && fstatus == GL_TRUE )
            std::cout << "Shaders Compiled Successfully." << std::endl;
        else{
            char buffer[512];
            glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
            std::cout << "Vertex Shader Compilation failed: " << buffer << std::endl;
            glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
            std::cout << "Fragment Shader Compilation failed: " << buffer << std::endl;
        }

        linkedShaderProgram = glCreateProgram();
        glAttachShader(linkedShaderProgram, vertexShader);
        glAttachShader(linkedShaderProgram, fragmentShader);
        glLinkProgram(linkedShaderProgram);
        glGetProgramiv(linkedShaderProgram, GL_LINK_STATUS, &lstatus);
        if(lstatus)
            std::cout << "Shaders linked successfully." << std::endl;
        else {
        char infoLog[512];
        glGetProgramInfoLog(linkedShaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Triangle::setUpMemoryLayout(){
        glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);
        glEnableVertexAttribArray(0);
    }
    void Triangle::mainLoop()
    {   
        glBindVertexArray(vao);
        glUseProgram(linkedShaderProgram);
        // Draw
        // glDrawArrays(GL_TRIANGLES,0,3);
        // Render Loop
        while (!glfwWindowShouldClose(window))
        {
            // Process Inputs
            windowHandling::processInput(window);
            // Draw
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glDrawArrays(GL_TRIANGLES,0,3);

            // Check and call events and swap the buffers
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void Triangle::initGLEW()
    {
        // glew checks
        // I am using glew, however in the tutorials GLAD is being used.
        GLenum err = glewInit();
        {
            if (GLEW_OK != err)
                throw std::runtime_error("Error initializing GLEW.");
            
            // To print out the opengl version with the vendor.
            std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
            fprintf(stdout, "GLEW: Using GLEW %s\n", glewGetString(GLEW_VERSION));
        }
    }
    void Triangle::cleanup()
    {
        // Clear resources.
        glDeleteVertexArrays(1,&vao);
        glDeleteBuffers(1,&vbo);
        glDeleteProgram(linkedShaderProgram);
        glfwTerminate();
    }
    void Triangle::createInstance() {}
} // namespace Triangle
