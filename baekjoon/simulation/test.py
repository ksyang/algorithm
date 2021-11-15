import sys

target_channel_string = input()
target_channel_int = int(target_channel_string)
target_channer_int_arr = list(map(int, target_channel_string))

current_channel = 100
button_count = 0 

# print (target_channel_string)

malfunc_button_number = int(input())
offset_buf = 0
if malfunc_button_number == 0:
   offset_buf = abs(current_channel - target_channel_int)
   if len(target_channel_string) > offset_buf:
      print(offset_buf)
   else:
      print (len(target_channel_string))
   sys.exit(0)

#if malfunc_button_number == 10:
#   print (abs(target_channel_int - current_channel))
#   sys.exit(0)

available_button_arr = [0,1,2,3,4,5,6,7,8,9]
malfunc_button_arr = list(map(int,input().split()))

# available_button_arr = del(malfunc_button_arr)
for value in malfunc_button_arr:
   available_button_arr.remove(value)

if current_channel == target_channel_int:
   print (button_count)
   sys.exit(0)

minimal_count = 0
minimal_offset = 10000000

# is_available_button = False

# test_button_int_set = list(map(int, '13678'))
# print (test_button_int_set)

# for button_value in test_button_int_set:
#    if button_value in malfunc_button_arr:
#       is_available_button == False
#       print (button_value)

minimal_offset_button = 0
for test_button in range(0, 1000000+1):
   test_button_int_arr = list(map(int, str(test_button)))
   # print (test_button_int_set)
   # available_button_set = set(available_button_arr)
   is_available_button = True
   for button_value in test_button_int_arr:
      if button_value in malfunc_button_arr:
         is_available_button = False
         break

   if is_available_button == False:
      continue

   offset_buf = abs(target_channel_int - test_button)
   if minimal_offset > offset_buf:
      minimal_offset = offset_buf
      minimal_offset_button = test_button

button_push_count = len(str(minimal_offset_button))
push_button_offset = abs(target_channel_int - minimal_offset_button)

print (button_push_count + push_button_offset)
