import json
import re 

path = './spritesheet.json'
output_file = 'spritsheet.txt' 

with open(path,'r') as json_file: 
    spritesheet = json.load(json_file)

'''
    Trying to extract tag in "filename"  
    Ex: 
        "filename": "mario_animation (fire_mario) 0.aseprite" 
        "filename": "mario_animation (fire_mario) 1.aseprite" 
    -> Trying to get fire_mario and number "0"
'''  
tag_pattern = "(?:(?<=\().+?(?=\))|(?<=\[).+?(?=\]))" 

tag_str = spritesheet["frames"][0]["filename"]
print(tag_str)
tag = re.search("(?:(?<=\().+?(?=\))|(?<=\[).+?(?=\]))",tag_str)
print(tag.group())








# print(len(spritesheet["frames"]))
# print("spritesheet_size: ",spritesheet["meta"]["size"])
# for idx in range(5): 
#       print(spritesheet["frames"][idx]["duration"]) 
#       print(spritesheet["frames"][idx]["filename"])
#       print(spritesheet["frames"][idx]["frame"])
#       print(spritesheet["frames"][idx]["duration"]) 
#       print("--------------------------------------") 

