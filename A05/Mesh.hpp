/**************
 Creae the meshes, as described below
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

void MakeSquare(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
 vertices = {
       {-size/2.0f,0.0f,-size/2.0f},
       {-size/2.0f,0.0f, size/2.0f},
       { size/2.0f,0.0f,-size/2.0f},
       { size/2.0f,0.0f, size/2.0f}};
 indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
    vertices = {
        {size/2.0f,size/2.0f,size/2.0f},
        {-size/2.0f,size/2.0f, size/2.0f},
        { -size/2.0f,-size/2.0f,size/2.0f},
        { size/2.0f,-size/2.0f, size/2.0f},
        
        {size/2.0f,size/2.0f,-size/2.0f},
        {-size/2.0f,size/2.0f, -size/2.0f},
        { -size/2.0f,-size/2.0f,-size/2.0f},
        { size/2.0f,-size/2.0f, -size/2.0f},
    };
                    
 indices = {
        0,1,2, 
        0,2,3, 
        0,2,1, 
        0,3,2, 
         
        2,6,1, 
        1,6,5, 
        2,1,6, 
        1,5,6, 
         
        4,6,7, 
        4,5,6, 
        4,7,6, 
        4,6,5, 
         
        1,0,4, 
        1,4,5, 
        1,4,0, 
        1,5,4, 
         
        0,3,7, 
        4,0,7, 
        0,7,3, 
        4,7,0, 
         
        2,3,6, 
        3,7,6, 
        2,6,3, 
        3,6,7 
     };

     /*
     {0,1,2,  2,3,0,
            0,3,4,  4,3,7,
            5,6,7,  7,4,5,
            1,6,5,  1,2,6,
            7,6,2,  3,2,7,
            4,5,0,  1,0,5}
            */

}
void MakeCylinder(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson

    vertices.resize(2*slices+2);
    indices.resize(12*slices);
    
    

	//generate vertices 0-31 33-64
    for(int i = 0; i < slices; i++) {
        float ang = 2*M_PI * (float)i / (float)slices;
        vertices[i] = glm::vec3(radius * sin(ang),-height/2,  radius * cos(ang));
        vertices[i+slices + 1] = glm::vec3(radius * sin(ang),height/2,  radius * cos(ang));
    }
    //generate vertex 32
    vertices[slices] = {0.0f,-height/2.0f,0.0f};

    //generate bottom circonference (0-32)
    for(int i = 0; i < slices; i++) {
        indices[3*i +1   ] = slices;   //prima è 96
        indices[3*i ] = i;            // ultima 191
        indices[3*i + 2] = (i+1) % slices; 
    }

    //generate vertex 65
    vertices[2*slices+1] = {0.0f,height/2.0f,0.0f};
    
    //generate top circonference (33-65)
    for(int i = 0; i < slices; i++) {
        indices[3*slices + 3*i   ] = 2*slices+1;   //prima è 97 v:65
        indices[3*slices + 3*i +1] = i+slices +1;            // ultima 287 v:33
        indices[3*slices + 3*i + 2] = (i+slices+2) % (2*slices+1); 
    }
    indices[191] = 33;
 
   
    //build the body
    for(int i = 0; i < slices; i++) {
        indices[6*slices + 3*i    ] = i;
        indices[6*slices + 3*i + 1] = (i+1) % slices;
        indices[6*slices + 3*i + 2] = i+slices+1; 
        // printf("%d, %d, %d\n", i, (i+1) % slices, i+slices+1);
    }
    
    printf("\n\n");

    for(int i = 0; i < slices; i++) {
        indices[9*slices + 3*i    ] = i;
        indices[9*slices + 3*i + 1] = (i+slices+1);
        indices[9*slices + 3*i + 2] = (i+ slices) % (2*slices);
     
        // printf("%d, %d, %d\n",i, (i+slices+1), (i+ slices) % (2*slices));
    }
    indices[9*slices + 2] = 2*slices;

    

}

void MakeCone(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
/*  vertices = {
       {-radius,-height/2.0f,0.0f},
       { radius,-height/2.0f,0.0f},
       { 0.0f, height/2.0f,0.0f}};
 indices = {0, 1, 2}; */
	
	vertices.resize(slices+2);
    indices.resize(12*slices);
    vertices[slices] = {0.0f,height/2.0f,0.0f};
    vertices[slices+1] = {0.0f,-height/2.0f,0.0f};

	//generate the cone
    for(int i = 0; i < slices; i++) {
        float ang = 2*M_PI * (float)i / (float)slices;
        vertices[i] = glm::vec3(radius * sin(ang),-height/2,  radius * cos(ang));
        indices[3*i  ] = slices;
        indices[3*i+1] = i;
        indices[3*i+2] = (i+1) % slices; //ultima è 95
    }

    //generate circonference
    for(int i = 0; i < slices; i++) {
        indices[3*slices + 3*i    ] = slices + 1; //prima è 96
        indices[3*slices + 3*i + 2] = i;
        indices[3*slices + 3*i + 1] = (i+1) % slices; // ultima 191
    }
}

void MakeSphere(float radius, int rings, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.
  // Resize the vertices and indices vectors to accommodate the sphere's data
    vertices.clear();
    indices.clear();
    
    // Loop through the rings
    for (int j = 0; j <= rings; ++j) {
        float theta = j * M_PI / rings; // Angle for the ring
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);
        
        // Loop through the slices
        for (int i = 0; i <= slices; ++i) {
            float phi = i * 2 * M_PI / slices; // Angle for the slice
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            glm::vec3 vertex;
            vertex.x = radius * cosPhi * sinTheta;
            vertex.y = radius * cosTheta;
            vertex.z = radius * sinPhi * sinTheta;

            vertices.push_back(vertex);
        }
    }

    // Generate the indices
    for (int j = 0; j < rings; ++j) {
        for (int i = 0; i < slices; ++i) {
            int first = (j * (slices + 1)) + i;
            int second = first + slices + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }
}