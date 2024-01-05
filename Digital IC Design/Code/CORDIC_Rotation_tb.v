`timescale 1ns/1ns 
`include "CORDIC_Rotation.v"

module CORDIC_Rotation_tb ();

    wire [31:0] x_out, y_out;
    reg [31:0] x_in, y_in, rotation_angle;

    reg clock = 1'b0;
    reg reset = 1'b0;

    always #1 clock = ~clock;

    initial 
    begin 
        
        x_in <= 32'd0;
        y_in <= 32'd1_0;
        rotation_angle <= 32'd90_0;

    end 

    CORDIC_Rotation mod (x_out, y_out, clock, reset, x_in, y_in, rotation_angle);

    initial 
    begin 

        $dumpfile("CORDIC_Rotation.vcd");
        $dumpvars;

        #20 $finish;

    end 

endmodule 