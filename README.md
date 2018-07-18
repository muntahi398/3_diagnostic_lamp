# DIFFERENT APPROACH FOR PUBlISH SUBSCRIBE
for cpu efficiency,  int_pub_3.cpp and int_pub_4.cpp used using all in classs, but pub_4 is better as the class itself callbacks itself.

int_sub_2.cpp used with all with class.


# 3_diagnostic_lamp

Publishes 3 Boolean value whch is messaged as Int8,

Subscribe that Int8 message and extract 3 bits which corresponds to that diagnostic condition

(Error, Warning, Heaalthy)

rosrun diagnostic_light diag_int_pub  
# publishes

rosrun diagnostic_light diag_int_sub1
'subscribes published message


