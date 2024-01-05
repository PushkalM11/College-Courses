module memory (product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    output reg [7:0] product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9;

    input clock, reset;
    input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;

    reg [7:0] memory_h0 [0:15];
    reg [7:0] memory_h1 [0:15];
    reg [7:0] memory_h2 [0:15];
    reg [7:0] memory_h3 [0:15];
    reg [7:0] memory_h4 [0:15];
    reg [7:0] memory_h5 [0:15];
    reg [7:0] memory_h6 [0:15];
    reg [7:0] memory_h7 [0:15];
    reg [7:0] memory_h8 [0:15];
    reg [7:0] memory_h9 [0:15];

    integer i;
    parameter h_0 = 1;
    parameter h_1 = 2;
    parameter h_2 = 3;
    parameter h_3 = 4;
    parameter h_4 = 5;
    parameter h_5 = 6;
    parameter h_6 = 7;
    parameter h_7 = 8;
    parameter h_8 = 9;
    parameter h_9 = 10;

    initial 
    begin 
        
        product_0 <= 8'b0000_0000;
        product_1 <= 8'b0000_0000;
        product_2 <= 8'b0000_0000;
        product_3 <= 8'b0000_0000;
        product_4 <= 8'b0000_0000;
        product_5 <= 8'b0000_0000;
        product_6 <= 8'b0000_0000;
        product_7 <= 8'b0000_0000;
        product_8 <= 8'b0000_0000;
        product_9 <= 8'b0000_0000;

        for (i = 0; i < 16; i++)
        begin 
            
            memory_h0[i] = (h_0 * i);
            memory_h1[i] = (h_1 * i);
            memory_h2[i] = (h_2 * i);
            memory_h3[i] = (h_3 * i);
            memory_h4[i] = (h_4 * i);
            memory_h5[i] = (h_5 * i);
            memory_h6[i] = (h_6 * i);
            memory_h7[i] = (h_7 * i);
            memory_h8[i] = (h_8 * i);
            memory_h9[i] = (h_9 * i);

        end 
    
    end

    always @(x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, reset)
    begin 
        
        if (reset)
        begin

            product_0 <= 8'b0000_0000;
            product_1 <= 8'b0000_0000;
            product_2 <= 8'b0000_0000;
            product_3 <= 8'b0000_0000;
            product_4 <= 8'b0000_0000;
            product_5 <= 8'b0000_0000;
            product_6 <= 8'b0000_0000;
            product_7 <= 8'b0000_0000;
            product_8 <= 8'b0000_0000;
            product_9 <= 8'b0000_0000;

        end 

        else 
        begin 
            
            product_0 <= memory_h0[x_0];
            product_1 <= memory_h1[x_1];
            product_2 <= memory_h2[x_2];
            product_3 <= memory_h3[x_3];
            product_4 <= memory_h4[x_4];
            product_5 <= memory_h5[x_5];
            product_6 <= memory_h6[x_6];
            product_7 <= memory_h7[x_7];
            product_8 <= memory_h8[x_8];
            product_9 <= memory_h9[x_9];

        end 

    end 

endmodule 

module correlation_4 (y, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    output reg [11:0] y;

	input clock, reset;
	input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;

    wire [7:0] product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9;

    memory mem (product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    initial 
    begin 
        y <= 12'b0000_0000_0000;
    end 

    always @(posedge clock, reset)
    begin 

        if (reset)
        begin 
            y <= 12'b0000_0000_0000;
        end 

        else 
        begin 
            y <= (product_0 + product_1 + product_2 + product_3 + product_4 + product_5 + product_6 + product_7 + product_8 + product_9);
        end 

    end 

endmodule 