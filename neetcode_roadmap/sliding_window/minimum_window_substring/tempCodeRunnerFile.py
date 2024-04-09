    if all(s_dict.get(key, 0) >= value for key, value in t_dict.items()):
                matches.append(s[l:r+1])
                
                if s[l] in t_dict:
                    s_dict[s[l]] = s_dict.get(s[r], 0) - 1
                    
                    if all(s_dict.get(key, 0) < value for key, value in t_dict.items()):
                        s_dict[s[l]] = s_dict.get(s[l],0) + 1
                    else:
        