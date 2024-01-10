import bpy

output_path = r"C:\Users\hugopm\Desktop\coords_out.txt"

with open(output_path, "w") as file:
    for ob in bpy.context.scene.objects:
        mat = ob.matrix_world
        loc = mat.translation * 10  # Multiply by 100 for scaling
        loc.x *= -1  # Invert X-axis
        
        rot = mat.to_euler()
        scale = ob.scale * 20
        
        # Formatting the output line
        output_line = f'sog.CreateRectangle({{{loc.x:.2f}, {loc.z:.2f}, {loc.y:.2f}}}, ' \
                      f'{{{rot.x:.2f}, {rot.y:.2f}, {rot.z:.2f}}}, ' \
                      f'{{{scale.x:.2f}, {scale.y:.2f}, {scale.z:.2f}}});'
        
        print(output_line)
        file.write(output_line + "\n")