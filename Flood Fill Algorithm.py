def ValidPixel(arr, rows, cols, x_Co_ordinate, y_Co_ordinate, Previous_Color, New_Color):
    
	if x_Co_ordinate<0 or x_Co_ordinate>= rows\
	or y_Co_ordinate<0 or y_Co_ordinate>= cols or\
        arr[x_Co_ordinate][y_Co_ordinate]!= Previous_Color\
	or arr[x_Co_ordinate][y_Co_ordinate]== New_Color:
            
		return False
	return True

def function_of_FloodFill_Algo(arr,rows, cols, x_Co_ordinate,y_Co_ordinate,Previous_Color , New_Color):
    
	queue = []

	queue.append([x_Co_ordinate,  y_Co_ordinate])

	arr[x_Co_ordinate][ y_Co_ordinate] =  New_Color

	while queue:

		current_pixel = queue.pop()
		
		position_of_X = current_pixel[0]
		position_of_Y = current_pixel[1]
		

		if ValidPixel(arr, rows, cols,position_of_X + 1, position_of_Y,Previous_Color,  New_Color):
                    
			arr[position_of_X + 1][position_of_Y] =  New_Color
			queue.append([position_of_X + 1, position_of_Y])
		
		if ValidPixel(arr, rows, cols,position_of_X-1, position_of_Y,Previous_Color,  New_Color):
                    
			arr[position_of_X-1][position_of_Y]=  New_Color
			queue.append([position_of_X-1, position_of_Y])
		
		if ValidPixel(arr, rows, cols,position_of_X, position_of_Y + 1,Previous_Color, New_Color):
                    
			arr[position_of_X][position_of_Y + 1]=  New_Color
			queue.append([position_of_X, position_of_Y + 1])
		
		if ValidPixel(arr, rows,cols,position_of_X, position_of_Y-1,Previous_Color, New_Color):
                    
			arr[position_of_X][position_of_Y-1]=  New_Color
			queue.append([position_of_X, position_of_Y-1])
arr =[
[1, 1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 0, 0],
[1, 0, 0, 1, 1, 0, 1, 1],
[1, 7, 7, 7, 7, 0, 1, 0],
[1, 1, 1, 7, 7, 0, 1, 0],
[1, 1, 1, 7, 7, 7, 7, 0],
[1, 1, 1, 1, 1, 7, 1, 1],
[1, 1, 1, 1, 1, 7, 7, 1],
	]
    
rows = len(arr)
cols = len(arr[0])

x_Co_ordinate = 4
y_Co_ordinate = 4

Previous_Color = arr[x_Co_ordinate][y_Co_ordinate]
New_Color = 5

function_of_FloodFill_Algo(arr, rows, cols, x_Co_ordinate,y_Co_ordinate, Previous_Color, New_Color)

for k in range(rows):
	for l in range(cols):
		print(arr[k][l], end =' ')
	print()
