#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asprintf.h"
#define put(index, char_array) (index >= 0? (char_array[index--]) : "")

char** aldos_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(17 * sizeof(char *));
    asprintf(&out[0],  "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s           # ## #           %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s        # ######## #        %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s      # ### ######## #      %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s     # #### ######### #     %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s   # #### # # # # #### #    %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s  # ##### #       ##### #   %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s   # ###### ##### #### #    %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    # ############### #     %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s         _ ___   ___  ___   %s", c2, put(num_info_lines, info));
    asprintf(&out[11], "%s    __ _| |   \\ / _ \\/ __|  %s", c2, put(num_info_lines, info));
    asprintf(&out[12], "%s   / _' | | |) | (_) \\__ \\  %s", c2, put(num_info_lines, info));
    asprintf(&out[13], "%s   \\__,_|_|___/ \\___/|___/  %s", c2, put(num_info_lines, info));
    asprintf(&out[14], "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s                            %s", c1, put(num_info_lines, info));
    out[16] = 0;

    return out;
}

char** antergos_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(20 * sizeof(char *));
    asprintf(&out[0],  "%s              `.-/::/-``                  %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s             .-/osssssssso/.              %s",    c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s            :osyysssssssyyys+-            %s",    c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s         `.+yyyysssssssssyyyyy+.          %s",   c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s        `/syyyyyssssssssssyyyyys-`        %s",  c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s       `/yhyyyyysss%s++%sssosyyyyhhy/`        %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s      .ohhhyyyys%so++/+o%sso%s+%ssyy%s+%sshhhho.      %s",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s     .shhhhys%soo++//+%ssss%s+++%syyy%s+s%shhhhs.     %s",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    -yhhhhs%s+++++++o%sssso%s+++%syyy%ss+o%shhddy:    %s",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s   -yddhhy%so+++++o%ssyyss%s++++%syyy%syooy%shdddy-   %s",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s  .yddddhs%so++o%ssyyyyys%s+++++%syyhh%ssos%shddddy`  %s",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s `odddddhyosyhyyyyyy%s++++++%syhhhyosddddddo  %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[12], "%s .dmdddddhhhhhhhyyyo%s+++++%sshhhhhohddddmmh. %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s ddmmdddddhhhhhhhso%s++++++%syhhhhhhdddddmmdy %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s dmmmdddddddhhhyso%s++++++%sshhhhhddddddmmmmh %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[15], "%s -dmmmdddddddhhys%so++++o%sshhhhdddddddmmmmd- %s",  c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[16], "%s .smmmmddddddddhhhhhhhhhdddddddddmmmms.   %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s    `+ydmmmdddddddddddddddddddmmmmdy/.    %s", c1, put(num_info_lines, info));
    asprintf(&out[18], "%s       `.:+ooyyddddddddddddyyso+:.`       %s", c1, put(num_info_lines, info));
    out[19] = 0;

    return out;
}

char** arch_old_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s              __                    %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s         _=(SDGJT=_                 %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s       _GTDJHGGFCVS)                %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s      ,GTDJGGDTDFBGX0               %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s     JDJDIJHRORVFSBSVL%s-=+=,_        %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[5],  "%s    IJFDUFHJNXIXCDXDSV,%s  \\\"DEBL     %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[6],  "%s   [LKDSDJTDU=OUSCSBFLD.%s   '?ZWX,   %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[7],  "%s  ,LMDSDSWH'     \\`DCBOSI%s     DRDS],%s", c1, c2, put(num_info_lines, info));
    asprintf(&out[8],  "%s  SDDFDFH'         !YEWD,%s   )HDROD  %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[9],  "%s !KMDOCG            &GSU|%s\\_GFHRGO\'  %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[10], "%s HKLSGP'%s           __%s\\TKM0%s\\GHRBV)'  %s", c1, c2, c1, c2, put(num_info_lines, info));
    asprintf(&out[11], "%sJSNRVW'%s       __+MNAEC%s\\IOI,%s\\BN'     %s", c1, c2, c1, c2, put(num_info_lines, info));
    asprintf(&out[12], "%sHELK['%s    __,=OFFXCBGHC%s\\FD)         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s?KGHE %s\\_-#DASDFLSV='%s    'EF         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s'EHTI                    !H         %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s \\`0F'                    '!        %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s                                    %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s                                  %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** arch_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(20 * sizeof(char *));
    asprintf(&out[0],  "%s                   -`                  %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s                  .o+`                 %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s                 `ooo/                 %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s                `+oooo:                %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s               `+oooooo:               %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s               -+oooooo+:              %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s             `/:-:++oooo+:             %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s            `/++++/+++++++:            %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s           `/++++++++++++++:           %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s          `/+++o%soooooooo%soooo/`         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s         %s./%sooosssso++osssssso%s+`        %s", c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s        .oossssso-````/ossssss+`       %s", c2, put(num_info_lines, info));
    asprintf(&out[12], "%s       -osssssso.      :ssssssso.      %s", c2, put(num_info_lines, info));
    asprintf(&out[13], "%s      :osssssss/        osssso+++.     %s", c2, put(num_info_lines, info));
    asprintf(&out[14], "%s     /ossssssss/        +ssssooo/-     %s", c2, put(num_info_lines, info));
    asprintf(&out[15], "%s   `/ossssso+/:-        -:/+osssso+-   %s", c2, put(num_info_lines, info));
    asprintf(&out[16], "%s  `+sso+:-`                 `.-/+oso:  %s", c2, put(num_info_lines, info));
    asprintf(&out[17], "%s `++:.                           `-/+/ %s", c2, put(num_info_lines, info));
    asprintf(&out[18], "%s .`                                 `/ %s", c2, put(num_info_lines, info));
    out[19] = 0;

    return out;
}