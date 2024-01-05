function [alpha1, alpha2, alpha3, beta4] = allocatePower_Four(h1, h2, h3, h4, method, N_monte_carlo)
        
    if strcmp(method, 'equal')
        
        alpha1 = 0.25 .* ones(1, N_monte_carlo);
        alpha2 = 0.25 .* ones(1, N_monte_carlo); 
        alpha3 = 0.25 .* ones(1, N_monte_carlo);
        beta4 = 0.25 .* ones(1, N_monte_carlo);
        
    end
    
    if strcmp(method, 'manual')
        
        alpha1 = 0.10 .* ones(1, N_monte_carlo) ./ 1.4;
        alpha2 = 0.25 .* ones(1, N_monte_carlo) ./ 1.4; 
        alpha3 = 0.45 .* ones(1, N_monte_carlo) ./ 1.4;
        beta4 = 0.60 .* ones(1, N_monte_carlo) ./ 1.4;
        
    end
    
    if strcmp(method, 'water_filling')
        
        alpha1 = zeros(1, N_monte_carlo);
        alpha2 = zeros(1, N_monte_carlo);
        alpha3 = zeros(1, N_monte_carlo);
        beta4 = zeros(1, N_monte_carlo);
        
        for i = 1 : N_monte_carlo
            
            c = (1 / h1(i)) + (1 / h2(i)) + (1 / h3(i)) + (1 / h4(i));
            alpha1(i) = c - (1 / h1(i));
            alpha2(i) = c - (1 / h2(i));
            alpha3(i) = c - (1 / h3(i));
            beta4(i) = c - (1 / h4(i));
            
        end
        
    end

end