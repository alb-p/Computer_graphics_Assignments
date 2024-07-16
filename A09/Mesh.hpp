

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

void MakeSquare(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   {-size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
	vertices = {
					{-size/2.0f, size/2.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   {-size/2.0f, size/2.0f, size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f, size/2.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f, size/2.0f, size/2.0f,0.0f,1.0f,0.0f},
				   {-size/2.0f,-size/2.0f,-size/2.0f,0.0f,-1.0f,0.0f},
				   {-size/2.0f,-size/2.0f, size/2.0f,0.0f,-1.0f,0.0f},
				   { size/2.0f,-size/2.0f,-size/2.0f,0.0f,-1.0f,0.0f},
				   { size/2.0f,-size/2.0f, size/2.0f,0.0f,-1.0f,0.0f},

				   
				   {-size/2.0f, size/2.0f,-size/2.0f,0.0f,0.0f,-1.0f},
				   {-size/2.0f, size/2.0f, size/2.0f,0.0f,0.0f,1.0f},
				   { size/2.0f, size/2.0f,-size/2.0f,0.0f,0.0f,-1.0f},
				   { size/2.0f, size/2.0f, size/2.0f,0.0f,0.0f,1.0f},
				   {-size/2.0f,-size/2.0f,-size/2.0f,0.0f,0.0f,-1.0f},
				   {-size/2.0f,-size/2.0f, size/2.0f,0.0f,0.0f,1.0f},
				   { size/2.0f,-size/2.0f,-size/2.0f,0.0f,0.0f,-1.0f},
				   { size/2.0f,-size/2.0f, size/2.0f,0.0f,0.0f,1.0f},

					{-size/2.0f, size/2.0f,-size/2.0f,-1.0f,0.0f,0.0f},
				   {-size/2.0f, size/2.0f, size/2.0f,-1.0f,0.0f,0.0f},
				   { size/2.0f, size/2.0f,-size/2.0f,1.0f,0.0f,0.0f},
				   { size/2.0f, size/2.0f, size/2.0f,1.0f,0.0f,0.0f},
				   {-size/2.0f,-size/2.0f,-size/2.0f,-1.0f,0.0f,0.0f},
				   {-size/2.0f,-size/2.0f, size/2.0f,-1.0f,0.0f,0.0f},
				   { size/2.0f,-size/2.0f,-size/2.0f,1.0f,0.0f,0.0f},
				   { size/2.0f,-size/2.0f, size/2.0f,1.0f,0.0f,0.0f}

				   };			   
				   
				   
	indices = {{// Top face
        0, 1, 2,  1, 3, 2,
        // Bottom face
        4, 6, 5,  5, 6, 7,
        // Front face
        8, 10, 12,  10, 14, 12,
        // Back face
        9, 13, 11,  11, 13, 15,
        // Left face
        16, 20, 17,  17, 20, 21,
        // Right face
        18, 19, 22,  19, 23, 22
			   }};

}

void MakeCylinder(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	vertices.clear();
    indices.clear();
    
    float halfHeight = height / 2.0f;
    float angleStep = 2.0f * M_PI / slices;

    // Generate vertices for the top and bottom faces
    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        
        // Top face vertex
        vertices.push_back({x, halfHeight, z, 0.0f, 1.0f, 0.0f});
        
        // Bottom face vertex
        vertices.push_back({x, -halfHeight, z, 0.0f, -1.0f, 0.0f});
    }

    // Center vertices for top and bottom faces
    vertices.push_back({0.0f, halfHeight, 0.0f, 0.0f, 1.0f, 0.0f});
    vertices.push_back({0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f});

    // Generate vertices for the sides
    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float nx = cos(angle);
        float nz = sin(angle);
        
        // Side vertices
        vertices.push_back({x, halfHeight, z, nx, 0.0f, nz});
        vertices.push_back({x, -halfHeight, z, nx, 0.0f, nz});
    }

    // Indices for top face
    int topCenterIndex = slices * 2;
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(topCenterIndex);
        indices.push_back(next * 2);
        indices.push_back(i * 2);
    }

    // Indices for bottom face
    int bottomCenterIndex = topCenterIndex + 1;
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        indices.push_back(bottomCenterIndex);
        indices.push_back(i * 2 + 1);
        indices.push_back(next * 2 + 1);
    }

    // Indices for sides
    int sideVertexStart = slices * 2 + 2;
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        int v0 = sideVertexStart + i * 2;
        int v1 = sideVertexStart + next * 2;
        int v2 = v0 + 1;
        int v3 = v1 + 1;
        
        // First triangle of the quad
        indices.push_back(v0);
        indices.push_back(v1);
        indices.push_back(v2);
        
        // Second triangle of the quad
        indices.push_back(v2);
        indices.push_back(v1);
        indices.push_back(v3);
    }
}

void MakeCone(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	 
	 
	/* 
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

	
	for(int i = 0; i < slices; i++) {
        float ang = 2*M_PI * (float)i / (float)slices;
        vertices.[i]={radius * sin(ang),-height/2,  radius * cos(ang), 0.0f,0.0f,1.0f};


		
		;
        vertices[i+slices + 1] = glm::vec3(radius * sin(ang),height/2,  radius * cos(ang));
    }

	*/
	vertices = {
				   {-radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { radius,-height/2.0f,0.0f,0.0f,0.0f,1.0f},
				   { 0.0f,   height/2.0f,0.0f,0.0f,0.0f,1.0f}};
	indices = {0, 1, 2};
}

void MakeSphere(float radius, int rings, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.
	vertices.resize(slices+1);
	indices.resize(3*slices);
	vertices[slices] = {0.0f,0.0f,0.0f,0.0f,0.0f,1.0f};
	for(int i = 0; i < slices; i++) {
		float ang = 2*M_PI * (float)i / (float)slices;
		vertices[i] = {radius * cos(ang), radius * sin(ang), 0.0f,0.0f,0.0f,1.0f};
		indices[3*i  ] = slices;
		indices[3*i+1] = i;
		indices[3*i+2] = (i+1) % slices;
	}
}
