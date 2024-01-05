module retrieve (product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    output reg [7:0] product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9;

    input clock, reset;
    input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;

    reg [3:0] h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9;

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
            
            product_0 <= x_0 + (x_0 << 2);
            product_1 <= (x_1 << 1) + (x_1 << 3);
            product_2 <= (x_2 << 1);
            product_3 <= (x_3 << 1) + (x_3 << 2);
            product_4 <= x_4 + (x_4 << 2) + (x_4 << 3);
            product_5 <= (x_5 << 1) + (x_5 << 2) + (x_5 << 3);
            product_6 <= x_6;
            product_7 <= x_7 + (x_7 << 3);
            product_8 <= x_8 << 3;
            product_9 <= x_9 + (x_9 << 1) + (x_9 << 2) + (x_9 << 3);

        end 

    end 

endmodule 

module correlation_5 (y, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

    output reg [11:0] y;

	input clock, reset;
	input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;

    wire [7:0] product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9;

    retrieve ret (product_0, product_1, product_2, product_3, product_4, product_5, product_6, product_7, product_8, product_9, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9);

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