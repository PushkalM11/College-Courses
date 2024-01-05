function [alpha1, alpha2, alpha3, alpha4, beta5] = allocatePower_five(h1, h2, h3, h4, h5, method, N_monte_carlo)
        
    if strcmp(method, 'equal')
        
        alpha1 = 0.2 .* ones(1, N_monte_carlo);
        alpha2 = 0.2 .* ones(1, N_monte_carlo); 
        alpha3 = 0.2 .* ones(1, N_monte_carlo);
        alpha4 = 0.2 .* ones(1, N_monte_carlo);
        beta5 = 0.2 .* ones(1, N_monte_carlo);
        
    end
    
    if strcmp(method, 'manual')
        
        alpha1 = 0.2 .* ones(1, N_monte_carlo);
        alpha2 = 0.2 .* ones(1, N_monte_carlo); 
        alpha3 = 0.2 .* ones(1, N_monte_carlo);
        alpha4 = 0.2 .* ones(1, N_monte_carlo);
        beta5 = 0.2 .* ones(1, N_monte_carlo);
        
    end
    
    if strcmp(method, 'water_filling')
        
        alpha1 = zeros(1, N_monte_carlo);
        alpha2 = zeros(1, N_monte_carlo);
        alpha3 = zeros(1, N_monte_carlo);
        alpha4 = zeros(1, N_monte_carlo);
        beta5 = zeros(1, N_monte_carlo);
        
        for i = 1 : N_monte_carlo
            
            c = (1 / h1(i)) + (1 / h2(i)) + (1 / h3(i)) + (1 / h4(i)) + (1 / h5(i));
            alpha1(i) = c - (1 / h1(i));
            alpha2(i) = c - (1 / h2(i));
            alpha3(i) = c - (1 / h3(i));
            alpha4(i) = c - (1 / h4(i));
            beta5(i) = c - (1 / h5(i));
            
        end
        
    end

end