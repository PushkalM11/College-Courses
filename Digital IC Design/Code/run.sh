iverilog -o correlation_1.vvp correlation_1_tb.v
vvp correlation_1.vvp 
gtkwave correlation_1.vcd

########################################################
########################################################

iverilog -o correlation_2.vvp correlation_2_tb.v
vvp correlation_2.vvp 
gtkwave correlation_2.vcd

########################################################
########################################################

iverilog -o correlation_3.vvp correlation_3_tb.v
vvp correlation_3.vvp 
gtkwave correlation_3.vcd

########################################################
########################################################

iverilog -o correlation_4.vvp correlation_4_tb.v
vvp correlation_4.vvp 
gtkwave correlation_4.vcd

########################################################
########################################################

iverilog -o correlation_5.vvp correlation_5_tb.v
vvp correlation_5.vvp 
gtkwave correlation_5.vcd

########################################################
########################################################

iverilog -o CORDIC_Vectoring.vvp CORDIC_Vectoring_tb.v
vvp CORDIC_Vectoring.vvp 
gtkwave CORDIC_Vectoring.vcd

########################################################
########################################################

iverilog -o CORDIC_Rotation.vvp CORDIC_Rotation_tb.v
vvp CORDIC_Rotation.vvp 
gtkwave CORDIC_Rotation.vcd