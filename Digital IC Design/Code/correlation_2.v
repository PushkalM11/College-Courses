module correlation_2 (y, clock, reset, x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9);
	
	output reg [11:0] y;

	input clock, reset;

	input [3:0] x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9;
	input [3:0] h_0, h_1, h_2, h_3, h_4, h_5, h_6, h_7, h_8, h_9;
	
	reg [7:0] mul_0, mul_1, mul_2, mul_3, mul_4, mul_5, mul_6, mul_7, mul_8, mul_9;

	always @(posedge clock)
	begin
		
		mul_0 <= x_0 * h_0;
		mul_1 <= x_1 * h_1;
		mul_2 <= x_2 * h_2;
		mul_3 <= x_3 * h_3;
		mul_4 <= x_4 * h_4;
		mul_5 <= x_5 * h_5;
		mul_6 <= x_6 * h_6;
		mul_7 <= x_7 * h_7;
		mul_8 <= x_8 * h_8;
		mul_9 <= x_9 * h_9;

	end

	always @(negedge clock, reset)
	begin
		
		if(reset) 
		begin
			y <= 12'b0000_0000_0000;
		end

		else
		begin
			y <= mul_0 + mul_1 + mul_2 + mul_3 + mul_4 + mul_5 + mul_6 + mul_7 + mul_8 + mul_9;
		end

	end	

endmodule