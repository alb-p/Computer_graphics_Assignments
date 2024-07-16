#!/bin/bash

# Directory containing shader files
shader_dir="shaders"
# Output directory for compiled shaders
output_dir="compiled_shaders"

# Create output directory if it doesn't exist
mkdir -p "$output_dir"

# Loop through each shader file in the shader directory and compile it
for shader_file in "$shader_dir"/*; do
  # Extract the base name and the extension
  filename=$(basename -- "$shader_file")
  extension="${filename##*.}"
  base_name="${filename%Shader.*}"
  
  # Determine the output file name based on the extension
  if [[ "$extension" == "frag" ]]; then
    output_file="${output_dir}/${base_name}Frag.spv"
  elif [[ "$extension" == "vert" ]]; then
    output_file="${output_dir}/${base_name}Vert.spv"
  else
    echo "Skipping unsupported file type: $filename"
    continue
  fi
  
  # Compile the shader
  glslc "$shader_file" -o "$output_file"
  
  # Check if the compilation was successful
  if [ $? -eq 0 ]; then
    echo "Successfully compiled $shader_file to $output_file"
  else
    echo "Failed to compile $shader_file"
  fi
done
