    // https://en.wikibooks.org/wiki/GLSL_Programming/Unity/Brushed_Metal
    #ifdef FRAGMENT
         
         void main()
         {
            vec3 normalDirection = normalize(varyingNormalDirection);
            vec3 tangentDirection = normalize(varyingTangentDirection);

            vec3 viewDirection = 
               normalize(_WorldSpaceCameraPos - vec3(position));
            vec3 lightDirection;
            float attenuation;

            if (0.0 == _WorldSpaceLightPos0.w) // directional light?
            {
               attenuation = 1.0; // no attenuation
               lightDirection = normalize(vec3(_WorldSpaceLightPos0));
            } 
            else // point or spot light
            {
               vec3 vertexToLightSource = 
                  vec3(_WorldSpaceLightPos0 - position);
               float distance = length(vertexToLightSource);
               attenuation = 1.0 / distance; // linear attenuation 
               lightDirection = normalize(vertexToLightSource);
            }
            
            vec3 halfwayVector = 
               normalize(lightDirection + viewDirection);
	    vec3 binormalDirection = 
               cross(normalDirection, tangentDirection);
            float dotLN = dot(lightDirection, normalDirection); 
               // compute this dot product only once
            
            vec3 ambientLighting = vec3(gl_LightModel.ambient) 
               * vec3(_Color);

            vec3 diffuseReflection = attenuation * vec3(_LightColor0) 
               * vec3(_Color) * max(0.0, dotLN);
            
            vec3 specularReflection;
            if (dotLN < 0.0) // light source on the wrong side?
            {
               specularReflection = vec3(0.0, 0.0, 0.0); 
                  // no specular reflection
            }
            else // light source on the right side
            {
               float dotHN = dot(halfwayVector, normalDirection);
               float dotVN = dot(viewDirection, normalDirection);
               float dotHTAlphaX = 
                  dot(halfwayVector, tangentDirection) / _AlphaX;
               float dotHBAlphaY = dot(halfwayVector, 
                  binormalDirection) / _AlphaY;

               specularReflection = attenuation * vec3(_SpecColor) 
                  * sqrt(max(0.0, dotLN / dotVN)) 
                  * exp(-2.0 * (dotHTAlphaX * dotHTAlphaX 
                  + dotHBAlphaY * dotHBAlphaY) / (1.0 + dotHN));
            }

            gl_FragColor = vec4(ambientLighting 
               + diffuseReflection + specularReflection, 1.0);
         }
         
         #endif