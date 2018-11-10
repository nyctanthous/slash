#include <stdio.h>
#define put(index, char_array) (index >= 0? (char_array[index--]) : "")

void aldos_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s           # ## #           %s\n", c1, put(num_info_lines, info));
    printf("%s        # ######## #        %s\n", c1, put(num_info_lines, info));
    printf("%s      # ### ######## #      %s\n", c1, put(num_info_lines, info));
    printf("%s     # #### ######### #     %s\n", c1, put(num_info_lines, info));
    printf("%s   # #### # # # # #### #    %s\n", c1, put(num_info_lines, info));
    printf("%s  # ##### #       ##### #   %s\n", c1, put(num_info_lines, info));
    printf("%s   # ###### ##### #### #    %s\n", c1, put(num_info_lines, info));
    printf("%s    # ############### #     %s\n", c1, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s         _ ___   ___  ___   %s\n", c2, put(num_info_lines, info));
    printf("%s    __ _| |   \\ / _ \\/ __|  %s\n", c2, put(num_info_lines, info));
    printf("%s   / _' | | |) | (_) \\__ \\  %s\n", c2, put(num_info_lines, info));
    printf("%s   \\__,_|_|___/ \\___/|___/  %s\n", c2, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
}

void antergos_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s              `.-/::/-``                  %s\n", c1, put(num_info_lines, info));
    printf("%s             .-/osssssssso/.              %s\n",    c1, put(num_info_lines, info));
    printf("%s            :osyysssssssyyys+-            %s\n",    c1, put(num_info_lines, info));
    printf("%s         `.+yyyysssssssssyyyyy+.          %s\n",   c1, put(num_info_lines, info));
    printf("%s        `/syyyyyssssssssssyyyyys-`        %s\n",  c1, put(num_info_lines, info));
    printf("%s       `/yhyyyyysss%s++%sssosyyyyhhy/`        %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s      .ohhhyyyys%so++/+o%sso%s+%ssyy%s+%sshhhho.      %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s     .shhhhys%soo++//+%ssss%s+++%syyy%s+s%shhhhs.     %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s    -yhhhhs%s+++++++o%sssso%s+++%syyy%ss+o%shhddy:    %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s   -yddhhy%so+++++o%ssyyss%s++++%syyy%syooy%shdddy-   %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s  .yddddhs%so++o%ssyyyyys%s+++++%syyhh%ssos%shddddy`  %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s `odddddhyosyhyyyyyy%s++++++%syhhhyosddddddo  %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s .dmdddddhhhhhhhyyyo%s+++++%sshhhhhohddddmmh. %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s ddmmdddddhhhhhhhso%s++++++%syhhhhhhdddddmmdy %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s dmmmdddddddhhhyso%s++++++%sshhhhhddddddmmmmh %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s -dmmmdddddddhhys%so++++o%sshhhhdddddddmmmmd- %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s .smmmmddddddddhhhhhhhhhdddddddddmmmms.   %s\n", c1, put(num_info_lines, info));
    printf("%s    `+ydmmmdddddddddddddddddddmmmmdy/.    %s\n", c1, put(num_info_lines, info));
    printf("%s       `.:+ooyyddddddddddddyyso+:.`       %s\n", c1, put(num_info_lines, info));
}

void arch_old_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s              __                    %s\n", c1, put(num_info_lines, info));
    printf("%s         _=(SDGJT=_                 %s\n", c1, put(num_info_lines, info));
    printf("%s       _GTDJHGGFCVS)                %s\n", c1, put(num_info_lines, info));
    printf("%s      ,GTDJGGDTDFBGX0               %s\n", c1, put(num_info_lines, info));
    printf("%s     JDJDIJHRORVFSBSVL%s-=+=,_        %s\n", c1, c2, put(num_info_lines, info));
    printf("%s    IJFDUFHJNXIXCDXDSV,%s  \\\"DEBL     %s\n", c1, c2, put(num_info_lines, info));
    printf("%s   [LKDSDJTDU=OUSCSBFLD.%s   '?ZWX,   %s\n", c1, c2, put(num_info_lines, info));
    printf("%s  ,LMDSDSWH'     \\`DCBOSI%s     DRDS],%s\n", c1, c2, put(num_info_lines, info));
    printf("%s  SDDFDFH'         !YEWD,%s   )HDROD  %s\n", c1, c2, put(num_info_lines, info));
    printf("%s !KMDOCG            &GSU|%s\\_GFHRGO\'  %s\n", c1, c2, put(num_info_lines, info));
    printf("%s HKLSGP'%s           __%s\\TKM0%s\\GHRBV)'  %s\n", c1, c2, c1, c2, put(num_info_lines, info));
    printf("%sJSNRVW'%s       __+MNAEC%s\\IOI,%s\\BN'     %s\n", c1, c2, c1, c2, put(num_info_lines, info));
    printf("%sHELK['%s    __,=OFFXCBGHC%s\\FD)         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s?KGHE %s\\_-#DASDFLSV='%s    'EF         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s'EHTI                    !H         %s\n", c1, put(num_info_lines, info));
    printf("%s \\`0F'                    '!        %s\n", c1, put(num_info_lines, info));
    printf("%s                                    %s\n", c1, put(num_info_lines, info));
    printf("%s                                  %s\n", c1, put(num_info_lines, info));
}

void arch_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s                   -`                  %s\n", c1, put(num_info_lines, info));
    printf("%s                  .o+`                 %s\n", c1, put(num_info_lines, info));
    printf("%s                 `ooo/                 %s\n", c1, put(num_info_lines, info));
    printf("%s                `+oooo:                %s\n", c1, put(num_info_lines, info));
    printf("%s               `+oooooo:               %s\n", c1, put(num_info_lines, info));
    printf("%s               -+oooooo+:              %s\n", c1, put(num_info_lines, info));
    printf("%s             `/:-:++oooo+:             %s\n", c1, put(num_info_lines, info));
    printf("%s            `/++++/+++++++:            %s\n", c1, put(num_info_lines, info));
    printf("%s           `/++++++++++++++:           %s\n", c1, put(num_info_lines, info));
    printf("%s          `/+++o%soooooooo%soooo/`         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s         %s./%sooosssso++osssssso%s+`        %s\n", c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s        .oossssso-````/ossssss+`       %s\n", c2, put(num_info_lines, info));
    printf("%s       -osssssso.      :ssssssso.      %s\n", c2, put(num_info_lines, info));
    printf("%s      :osssssss/        osssso+++.     %s\n", c2, put(num_info_lines, info));
    printf("%s     /ossssssss/        +ssssooo/-     %s\n", c2, put(num_info_lines, info));
    printf("%s   `/ossssso+/:-        -:/+osssso+-   %s\n", c2, put(num_info_lines, info));
    printf("%s  `+sso+:-`                 `.-/+oso:  %s\n", c2, put(num_info_lines, info));
    printf("%s `++:.                           `-/+/ %s\n", c2, put(num_info_lines, info));
    printf("%s .`                                 `/ %s\n", c2, put(num_info_lines, info));
}