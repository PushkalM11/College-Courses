`timescale 1ns/1ns 
`include "correlation_5.v"

module correlation_5_tb ();

    reg [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;
    reg [3:0] h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9;

    reg reset = 1'b0;
    reg clock = 1'b1;

    wire [11:0] out;

    always #1 clock <= ~clock;

    correlation_5 corr_5 (out, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    integer expected_output;

    initial 
    begin

        h_0 <= 4'b0101;
        h_1 <= 4'b1010;
        h_2 <= 4'b0010;
        h_3 <= 4'b0110;
        h_4 <= 4'b1101;
        h_5 <= 4'b1110;
        h_6 <= 4'b0001;
        h_7 <= 4'b1001;
        h_8 <= 4'b1000;
        h_9 <= 4'b1111;

        $dumpfile("correlation_5.vcd");
        $dumpvars;

        #50 $finish;

    end

    always @(posedge clock)
    begin 

        x_0 <= $random;
        x_1 <= $random;
        x_2 <= $random;
        x_3 <= $random;
        x_4 <= $random;
        x_5 <= $random;
        x_6 <= $random;
        x_7 <= $random;
        x_8 <= $random;
        x_9 <= $random;

        #2;

    end  

    always @(x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9)
    begin 
        expected_output = (x_0 * h_0) + (x_1 * h_1) + (x_2 * h_2) + (x_3 * h_3) + (x_4 * h_4) + (x_5 * h_5) + (x_6 * h_6) + (x_7 * h_7) + (x_8 * h_8) + (x_9 * h_9);
    end

endmodule 