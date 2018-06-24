# 3_diagnostic_lamp

Publishes 3 Boolean value whch is messaged as Int8,

Subscribe that Int8 message and extract 3 bits which corresponds to that diagnostic condition

(Error, Warning, Heaalthy)

rosrun diagnostic_light diag_int_pub  
# publishes

rosrun diagnostic_light diag_int_sub1
'subscribes published message
