

void SetProjections(A03 *A) {
/**************
 Using A->SetMatrix(i, M) where:
 i -> index of the matrix to set (0 .. 7)
 M -> projection matrix to use

 define eight different types of projections.
 
 0 - Ortogonal Front (already given)
 1 - Isometric
 2 - Dimetric, with an angle of 20 degree
 3 - Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
 4 - Create a Cabinet projection, with the z axis at an angle of 45 degrees
 5 - Create a perspective projection, with a Fov-y of  90 degrees
 6 - Create a perspective projection, with a Fov-y of  30 degrees (zoom)
 7 - Create a perspective projection, with a Fov-y of 120 degrees (wide)

 Projection of type 0 is already done for you. Please create the other seven cases.
 For all the projections, the aspect ratio is supposed to be 4:3 (assuming the application
 is used on a screen with square pixels). Near plane is at 0.1 for perspective and orthogonal,
 while it is at -500 for isometric, dimetric, trimenteric and cabinet.
 The far plane is always at 500.
 For the parlallel projections, the half-width of the screen in world coordinates
 is assumed to be 20.
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/
//	glm::mat4 M;
	glm::mat4 M;
	glm::mat4 Rx, Ry, Sr;
	// Port1 for perspective and orthogonal, Port2 for isometric, dimetric, trimenteric and cabinet
	glm::mat4 Port1, Port2;

	// l = -w, r = w, t = w/a, b = -w/a

	float hw = 20.0f;
	float a = 4/3;
	float l = -hw;
	float r = hw;
	float t = hw / a;
	float b = -hw / a;	
	float n1 = 0.1f;
	float n2 = -500.0f;
	float f = 500.0f;

	//This added matrix product flips the y-axis to match the Vulkan conventions.
	Port1 = glm::scale(glm::mat4(1), glm::vec3(1,-1,1))*glm::ortho(l, r, b, t, n1, f);
	Port2 = glm::scale(glm::mat4(1), glm::vec3(1,-1,1))*glm::ortho(l, r, b, t, n2, f);



	// Ortogonal Front
	// this is the only one correct, and that should not be modified
	M = glm::mat4(1.0f / 20.0f,0,0,0,  0,-4.0f / 60.f,0,0,   0,0,1.0f/(0.1f-500.0f),0, 0,0,0.1f/(0.1f-500.0f),1);
	A->SetMatrix(0,  M);

	// Isometric
	Rx = glm::rotate(glm::mat4(1), glm::radians(35.26f), glm::vec3(1,0,0));
	Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0,1,0));
	M = Port2 * Rx * Ry;
	A->SetMatrix(1,  M);

	// Dimetric, with an angle of 20 degree
	Rx = glm::rotate(glm::mat4(1), glm::radians(20.0f), glm::vec3(1,0,0));
	Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0,1,0));
	M = Port2 * Rx * Ry;
	A->SetMatrix(2,  M);
	
	// Trimetric, with an angle of alpha of 30 degree, and beta of 60 degrees
	Ry = glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0,1,0));
	Rx = glm::rotate(glm::mat4(1), glm::radians(30.0f), glm::vec3(1,0,0));
	M = Port2 * Rx * Ry;
	A->SetMatrix(3,  M);
	
	// Create a Cabinet projection, with the z axis at an angle of 45 degrees
	// hx = −𝜌cos 𝛼
	// hy = −𝜌sin 𝛼
	// glm::mat4 Rx = glm::shearZ3D(glm::mat4(1), hx, hy);
	float hx = - 0.5 * cos(glm::radians(45.0f));
	float hy = - 0.5 * sin(glm::radians(45.0f));
	Sr = glm::shearZ3D(glm::mat4(1.0f), hx, hy);
	M = Port2 * Sr;
	A->SetMatrix(4,  M);
	
	// Create a perspective projection, with a Fov-y of  90 degrees
	M = glm::perspective(glm::radians(90.0f), a, n1, f);
	M[1][1] *= -1;
	A->SetMatrix(5,  M);
	
	// Create a perspective projection, with a Fov-y of  30 degrees (zoom)
	M = glm::perspective(glm::radians(30.0f), a, n1, f);
	M[1][1] *= -1;
	A->SetMatrix(6,  M);
	
	// Create a perspective projection, with a Fov-y of 120 degrees (wide)
	// Port1
	M = glm::perspective(glm::radians(120.0f), a, n1, f);
	M[1][1] *= -1;
	A->SetMatrix(7,  M); 
}
