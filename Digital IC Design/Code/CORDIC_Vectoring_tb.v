`timescale 1ns/1ns
`include "CORDIC_Vectoring.v"

module CORDIC_Vectoring_tb();

    wire [31:0] norm, angle;
    reg [31:0] x_in, y_in;

    reg clock = 1'b1;
    reg reset = 1'b0;

    always #1 clock = ~clock;

    initial 
    begin 

        x_in <= 32'd00_00;
        y_in <= 32'd10_00;

    end 

    CORDIC_Vectoring mod (norm, angle, clock, reset, x_in, y_in);

    initial 
    begin 

        $dumpfile("CORDIC_Vectoring.vcd");  
        $dumpvars;

        #24 $finish;

    end

endmodule 