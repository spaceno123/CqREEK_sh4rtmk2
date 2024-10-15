/************************************************************************/
/*      SH7750 Series Include File                         Ver 1.2      */
/************************************************************************/
struct st_sci {                                         /* struct SCI   */
              union {                                   /* SMR          */
                    unsigned char  BYTE;                /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char CA  :1;        /*    C/A       */
                           unsigned char CHR :1;        /*    CHR       */
                           unsigned char PE  :1;        /*    PE        */
                           unsigned char OE  :1;        /*    O/E       */
                           unsigned char STOP:1;        /*    STOP      */
                           unsigned char MP  :1;        /*    MP        */
                           unsigned char CKS :2;        /*    CKS       */
                           }       BIT;                 /*              */
                    }         SCSMR;                    /*              */
              char               wk1[3];                /*              */
              unsigned char   SCBRR;                    /* BRR          */
              char               wk2[3];                /*              */
              union {                                   /* SCR          */
                    unsigned char  BYTE;                /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TIE :1;        /*    TIE       */
                           unsigned char RIE :1;        /*    RIE       */
                           unsigned char TE  :1;        /*    TE        */
                           unsigned char RE  :1;        /*    RE        */
                           unsigned char MPIE:1;        /*    MPIE      */
                           unsigned char TEIE:1;        /*    TEIE      */
                           unsigned char CKE :2;        /*    CKE       */
                           }       BIT;                 /*              */
                    }         SCSCR;                    /*              */
              char               wk3[3];                /*              */
              unsigned char   SCTDR;                    /* TDR          */
              char               wk4[3];                /*              */
              union {                                   /* SSR          */
                    unsigned char  BYTE;                /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TDRE:1;        /*    TDRE      */
                           unsigned char RDRF:1;        /*    RDRF      */
                           unsigned char ORER:1;        /*    ORER      */
                           unsigned char FER :1;        /*    FER       */
                           unsigned char PER :1;        /*    PER       */
                           unsigned char TEND:1;        /*    TEND      */
                           unsigned char MPB :1;        /*    MPB       */
                           unsigned char MPBT:1;        /*    MPBT      */
                           }       BIT;                 /*              */
                    }         SCSSR;                    /*              */
              char               wk5[3];                /*              */
              unsigned char   SCRDR;                    /* RDR          */
              char               wk6[3];                /*              */
              union {                                   /* SCMR         */
                    unsigned char  BYTE;                /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char     :4;        /*              */
                           unsigned char SDIR:1;        /*    SDIR      */
                           unsigned char SINV:1;        /*    SINV      */
                           unsigned char     :1;        /*              */
                           unsigned char SMIF:1;        /*    SMIF      */
                           }       BIT;                 /*              */
                    }         SCSCMR;                   /*              */
              char               wk7[8];                /*              */
              union {                                   /* SCSPTR       */
                    unsigned char  BYTE;                /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char EIO :1;        /*              */
                           unsigned char     :3;        /*              */
                           unsigned char SPB1IO:1;      /*    SPB1IO    */
                           unsigned char SPB1DT:1;      /*    SPB1DT    */
                           unsigned char SPB0IO:1;      /*    SPB0IO    */
                           unsigned char SPB0DT:1;      /*    SPB0DT    */
                           }       BIT;                 /*              */
                    }         SCSPTR;                   /*              */
};                                                      /*              */
struct st_scif {                                        /* struct SCIF  */
              union {                                   /* SMR          */
                    unsigned short  WORD;               /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned short     :8;       /*              */
                           unsigned short     :1;       /*              */
                           unsigned short CHR :1;       /*    CHR       */
                           unsigned short PE  :1;       /*    PE        */
                           unsigned short OE  :1;       /*    O/E       */
                           unsigned short STOP:1;       /*    STOP      */
                           unsigned short     :1;       /*              */
                           unsigned short CKS :2;       /*    CKS       */
                           }       BIT;                 /*              */
                    }         SCSMR ;                   /*              */
              char               wk1[2];                /*              */
              unsigned char   SCBRR ;                   /* BRR          */
              char               wk2[3];                /*              */
              union {                                   /* SCR          */
                    unsigned short  WORD;               /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned short     :8;       /*              */
                           unsigned short TIE :1;       /*    TIE       */
                           unsigned short RIE :1;       /*    RIE       */
                           unsigned short TE  :1;       /*    TE        */
                           unsigned short RE  :1;       /*    RE        */
                           unsigned short REIE:1;       /*    REIE      */
                           unsigned short     :1;       /*              */
                           unsigned short CKE :1;       /*    CKE       */
                           unsigned short     :1;       /*              */
                           }       BIT;                 /*              */
                    }         SCSCR ;                   /*              */
              char               wk3[2];                /*              */
              unsigned char   SCFTDR ;                  /* TDR          */
              char               wk4[3];                /*              */
              union {                                   /* FSR          */
                    unsigned short  WORD;               /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned short PER3:4;       /*    PER3      */
                           unsigned short FER3:4;       /*    FER3      */
                           unsigned short ER  :1;       /*    ER        */
                           unsigned short TEND:1;       /*    TEND      */
                           unsigned short TDFE:1;       /*    TDFE      */
                           unsigned short BRK :1;       /*    BRK       */
                           unsigned short FER :1;       /*    FER       */
                           unsigned short PER :1;       /*    PER       */
                           unsigned short RDF :1;       /*    RDF       */
                           unsigned short DR  :1;       /*    DR        */
                           }       BIT;                 /*              */
                    }         SCFSR ;                   /*              */
              char               wk5[2];                /*              */
              unsigned char   SCFRDR ;                  /* RDR          */
              char               wk6[3];                /*              */
              union {                                   /* SCFCR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned short      :8;      /*              */
                           unsigned short RTRG :2;      /*    RTRG      */
                           unsigned short TTGR :2;      /*    TTRG      */
                           unsigned short MCE  :1;      /*    MCE       */
                           unsigned short TFRST:1;      /*    TFRST     */
                           unsigned short RFRST:1;      /*    RFRST     */
                           unsigned short LOOP :1;      /*    LOOP      */
                           }       BIT;                 /*              */
                    }         SCFCR ;                   /*              */
              char               wk7[2];                /*              */
              union {                                   /* SSR          */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned short    :3 ;       /*              */
                           unsigned short T  :5 ;       /*    T         */
                           unsigned short    :3 ;       /*              */
                           unsigned short R  :5 ;       /*    R         */
                           }       BIT;                 /*              */
                    }         SCFDR ;                   /*              */
              char               wk8[2];                /*              */
              union {                                   /* SCSPTR2      */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned short    :8 ;       /*              */
                           unsigned short RTSIO:1;      /*    RTSIO     */
                           unsigned short RTSDT:1;      /*    RTSTD     */
                           unsigned short CTSIO:1;      /*    CTSIO     */
                           unsigned short CTSDT:1;      /*    CTSDT     */
                           unsigned short    :2 ;       /*              */
                           unsigned short SPB2IO:1;     /*    SPB2IO    */
                           unsigned short SPB2DT:1;     /*    SPB2DT    */
                           }       BIT;                 /*              */
                    }         SCSPTR ;                  /*              */
              char               wk9[2];                /*              */
              union {                                   /* SSR          */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned short    :15;       /*              */
                           unsigned short ORER:1;       /*    ORER      */
                           }       BIT;                 /*              */
                    }         SCLSR ;                   /*              */
};                                                      /*              */
struct st_tmu  {                                        /* struct TMU   */
               union {                                  /* TOCR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :7;       /*              */
                            unsigned char TCOE:1;       /*    TCOE      */
                            }       BIT;                /*              */
                     }          TOCR;                   /*              */
               char               wk[3];                /*              */
               union {                                  /* TSTR         */
                     unsigned char  BYTE;               /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char STR2:1;       /*    STR2      */
                            unsigned char STR1:1;       /*    STR1      */
                            unsigned char STR0:1;       /*    STR0      */
                            }       BIT;                /*              */
                     }          TSTR;                   /*              */
};                                                      /*              */
struct st_tmu0 {                                        /* struct TMU0  */
               unsigned int   TCOR;                     /* TCOR         */
               unsigned int   TCNT;                     /* TCNT         */
               union {                                  /* TCR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short UNF :1;      /*    UNF       */
                            unsigned short     :2;      /*              */
                            unsigned short UNIE:1;      /*    UNIE      */
                            unsigned short CKEG:2;      /*    CKEG      */
                            unsigned short TPSC:3;      /*    TPSC      */
                            }       BIT;                /*              */
                     }          TCR;                    /*              */
};                                                      /*              */
struct st_tmu2 {                                        /* struct TMU2  */
               unsigned int   TCOR;                     /* TCOR         */
               unsigned int   TCNT;                     /* TCNT         */
               union {                                  /* TCR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :6;      /*              */
                            unsigned short ICPF:1;      /*    ICPF      */
                            unsigned short UNF :1;      /*    UNF       */
                            unsigned short ICPE:2;      /*    ICPE      */
                            unsigned short UNIE:1;      /*    UNIE      */
                            unsigned short CKEG:2;      /*    CKEG      */
                            unsigned short TPSC:3;      /*    TPSC      */
                            }       BIT;                /*              */
                     }          TCR;                    /*              */
               unsigned int   TCPR;                     /* TCPR         */
};                                                      /*              */
struct st_rtc {                                         /* struct RTC   */
               union {                                  /* R64CNT       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :1;       /*              */
                            unsigned char  Hz1:1;       /*     1Hz      */
                            unsigned char  Hz2:1;       /*     2Hz      */
                            unsigned char  Hz4:1;       /*     4Hz      */
                            unsigned char  Hz8:1;       /*     8Hz      */
                            unsigned char Hz16:1;       /*    16Hz      */
                            unsigned char Hz32:1;       /*    32Hz      */
                            unsigned char Hz64:1;       /*    64Hz      */
                            }       BIT;                /*              */
                     }          R64CNT;                 /*              */
               char             wk1[3];                 /*              */
               union {                                  /* RSECCNT      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :1;       /*              */
                            unsigned char  S10:3;       /*     10sec    */
                            unsigned char   S1:4;       /*      1sec    */
                            }       BIT;                /*              */
                     }          RSECCNT;                /*              */
               char             wk2[3];                 /*              */
               union {                                  /* RMINCNT      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :1;       /*              */
                            unsigned char  M10:3;       /*     10min    */
                            unsigned char   M1:4;       /*      1min    */
                            }       BIT;                /*              */
                     }          RMINCNT;                /*              */
               char             wk3[3];                 /*              */
               union {                                  /* RHRCNT       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :2;       /*              */
                            unsigned char  H10:2;       /*     10sec    */
                            unsigned char   H1:4;       /*      1sec    */
                            }       BIT;                /*              */
                     }          RHRCNT;                 /*              */
               char             wk4[3];                 /*              */
               union {                                  /* RWKCNT       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char  WK :3;       /*     week     */
                            }       BIT;                /*              */
                     }          RWKCNT;                 /*              */
               char             wk5[3];                 /*              */
               union {                                  /* RDAYCNT      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :2;       /*              */
                            unsigned char  D10:2;       /*     10day    */
                            unsigned char   D1:4;       /*      1day    */
                            }       BIT;                /*              */
                     }          RDAYCNT;                /*              */
               char             wk6[3];                 /*              */
               union {                                  /* RMONCNT      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :3;       /*              */
                            unsigned char  M10:1;       /*     10mon    */
                            unsigned char   M1:4;       /*      1mon    */
                            }       BIT;                /*              */
                     }          RMONCNT;                /*              */
               char             wk7[3];                 /*              */
               union {                                  /* RYRCNT       */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short Y1000:4;     /*   1000year   */
                            unsigned short  Y100:4;     /*    100year   */
                            unsigned short   Y10:4;     /*     10year   */
                            unsigned short    Y1:4;     /*      1year   */
                            }       BIT;                /*              */
                     }          RYRCNT;                 /*              */
               char             wk8[2];                 /*              */
               union {                                  /* RSECAR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char  S10:3;       /*     10sec    */
                            unsigned char   S1:4;       /*      1sec    */
                            }       BIT;                /*              */
                     }          RSECAR;                 /*              */
               char             wk9[3];                 /*              */
               union {                                  /* RMINAR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char  M10:3;       /*     10min    */
                            unsigned char   M1:4;       /*      1min    */
                            }       BIT;                /*              */
                     }          RMINAR;                 /*              */
               char             wk10[3];                /*              */
               union {                                  /* RHRAR        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char     :1;       /*              */
                            unsigned char  H10:2;       /*     10sec    */
                            unsigned char   H1:4;       /*      1sec    */
                            }       BIT;                /*              */
                     }          RHRAR;                  /*              */
               char             wk11[3];                /*              */
               union {                                  /* RWKAR        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char     :4;       /*              */
                            unsigned char  WK :3;       /*     week     */
                            }       BIT;                /*              */
                     }          RWKAR;                  /*              */
               char             wk12[3];                /*              */
               union {                                  /* RDAYAR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char     :1;       /*              */
                            unsigned char  D10:2;       /*     10day    */
                            unsigned char   D1:4;       /*      1day    */
                            }       BIT;                /*              */
                     }          RDAYAR;                 /*              */
               char             wk13[3];                /*              */
               union {                                  /* RMONAR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  ENB:1;       /*              */
                            unsigned char     :2;       /*              */
                            unsigned char  M10:1;       /*     10mon    */
                            unsigned char   M1:4;       /*      1mon    */
                            }       BIT;                /*              */
                     }          RMONAR;                 /*              */
               char             wk14[3];                /*              */
               union {                                  /* RCR1        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  CF :1;       /*     CF       */
                            unsigned char     :2;       /*              */
                            unsigned char  CIE:1;       /*     CIE      */
                            unsigned char  AIE:1;       /*     AIE      */
                            unsigned char     :2;       /*              */
                            unsigned char  AF :1;       /*     AF       */
                            }       BIT;                /*              */
                     }          RCR1;                   /*              */
               char             wk15[3];                /*              */
               union {                                  /* RCR2         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char  PEF :1;      /*     PEF      */
                            unsigned char  PES :3;      /*     PES      */
                            unsigned char RTCEN:1;      /*     RTCEN    */
                            unsigned char  ADJ :1;      /*     ADJ      */
                            unsigned char RESET:1;      /*     RESET    */
                            unsigned char START:1;      /*     START    */
                            }       BIT;                /*              */
                     }          RCR2;                   /*              */
};                                                      /*              */
struct st_intc {                                        /* struct INTC  */
               union {                                  /* ICR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short NMIL:1;      /*    NMIL      */
                            unsigned short MAI :1;      /*    MAI       */
                            unsigned short     :4;      /*              */
                            unsigned short NMIB:1;      /*    NMIB      */
                            unsigned short NMIE:1;      /*    NMIE      */
                            unsigned short IRLM:1;      /*    IRLM      */
                            }       BIT;                /*              */
                     }          ICR;                    /*              */
               char             wk1 [2];                /*              */
               union {                                  /* IPRA         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short UU:4;        /*    IRQ0      */
                            unsigned short UL:4;        /*    IRQ1      */
                            unsigned short LU:4;        /*    IRQ2      */
                            unsigned short LL:4;        /*    IRQ3      */
                            }       BIT;                /*              */
                     }          IPRA;                   /*              */
               char             wk2 [2];                /*              */
               union {                                  /* IPRB         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short UU:4;        /*    IRQ4      */
                            unsigned short UL:4;        /*    IRQ5      */
                            unsigned short LU:4;        /*    IRQ6      */
                            unsigned short LL:4;        /*    IRQ7      */
                            }       BIT;                /*              */
                     }          IPRB;                   /*              */
               char             wk3 [2];                /*              */
               union {                                  /* IPRC         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short UU:4;        /*    IRQ4      */
                            unsigned short UL:4;        /*    IRQ5      */
                            unsigned short LU:4;        /*    IRQ6      */
                            unsigned short LL:4;        /*    IRQ7      */
                            }       BIT;                /*              */
                     }          IPRC;                   /*              */
};                                                      /*              */
struct st_exp {                                         /* struct EXP   */
               unsigned int   TRA;                      /* TRA          */
               unsigned int   EXPEVT;                   /* EXPEVT       */
               unsigned int   INTEVT;                   /* INTEVT       */
};                                                      /*              */
struct st_bsc {                                         /* struct BSC   */
             union {                                    /*  BCR1        */
                   unsigned int    LONG ;               /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int  ENDIAN :1;      /*              */
                          unsigned int  MASTER :1;      /*              */
                          unsigned int  A0MPX  :1;      /*              */
                          unsigned int         :3;      /*              */
                          unsigned int  IPUP   :1;      /*              */
                          unsigned int  OPUP   :1;      /*              */
                          unsigned int         :2;      /*              */
                          unsigned int  A1MBC  :1;      /*              */
                          unsigned int  A4MBC  :1;      /*              */
                          unsigned int  BREQEN :1;      /*              */
                          unsigned int  PSHR   :1;      /*              */
                          unsigned int  MEMMPX :1;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   HIZMEM:1;      /*              */
                          unsigned int   HIZCNT:1;      /*              */
                          unsigned int   A0BST :3;      /*              */
                          unsigned int   A5BST :3;      /*              */
                          unsigned int   A6BST :3;      /*              */
                          unsigned int   DRAMTP:3;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A56PCM:1;      /*              */
                          }          BIT;               /*              */
                   }            BCR1;                   /*              */
             union {                                    /*  BCR2        */
                   unsigned short    WORD;              /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short A0SZ  :2;      /*              */
                          unsigned short A6SZ  :2;      /*              */
                          unsigned short A5SZ  :2;      /*              */
                          unsigned short A4SZ  :2;      /*              */
                          unsigned short A3SZ  :2;      /*              */
                          unsigned short A2SZ  :2;      /*              */
                          unsigned short A1SZ  :2;      /*              */
                          unsigned short       :1;      /*              */
                          unsigned short PORTEN:1;      /*              */
                          }          BIT;               /*              */
                   }            BCR2;                   /*              */
               char             wk1 [2];                /*              */
             union {                                    /*  WCR1        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int   DMAIW :4;      /*              */
                          unsigned int   A6IW  :4;      /*              */
                          unsigned int   A5IW  :4;      /*              */
                          unsigned int   A4IW  :4;      /*              */
                          unsigned int   A3IW  :4;      /*              */
                          unsigned int   A2IW  :4;      /*              */
                          unsigned int   A1IW  :4;      /*              */
                          unsigned int   A0IW  :4;      /*              */
                          }          BIT;               /*              */
                   }            WCR1;                   /*              */
             union {                                    /*  WCR2        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int   A6W   :3;      /*              */
                          unsigned int   A6B   :3;      /*              */
                          unsigned int   A5W   :3;      /*              */
                          unsigned int   A5B   :3;      /*              */
                          unsigned int   A4W   :3;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A3W   :3;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A2W   :3;      /*              */
                          unsigned int   A1W   :3;      /*              */
                          unsigned int   A0W   :3;      /*              */
                          unsigned int   A0B   :3;      /*              */
                          }          BIT;               /*              */
                   }            WCR2;                   /*              */
             union {                                    /*  WCR3        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int         :5;      /*              */
                          unsigned int   A6S0  :1;      /*              */
                          unsigned int   A6H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A5S0  :1;      /*              */
                          unsigned int   A5H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A4S0  :1;      /*              */
                          unsigned int   A4H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A3S0  :1;      /*              */
                          unsigned int   A3H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A2S0  :1;      /*              */
                          unsigned int   A2H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A1S0  :1;      /*              */
                          unsigned int   A1H   :2;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   A0S0  :1;      /*              */
                          unsigned int   A0H   :2;      /*              */
                          }          BIT;               /*              */
                   }            WCR3;                   /*              */
             union {                                    /*  MCR         */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int   RASD  :1;      /*              */
                          unsigned int   MRSET :1;      /*              */
                          unsigned int   TRC   :3;      /*              */
                          unsigned int         :3;      /*              */
                          unsigned int   TCAS  :1;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   TPC   :3;      /*              */
                          unsigned int         :1;      /*              */
                          unsigned int   RCD   :2;      /*              */
                          unsigned int   TRWL  :3;      /*              */
                          unsigned int   TRAS  :3;      /*              */
                          unsigned int   BE    :1;      /*              */
                          unsigned int   SZ    :2;      /*              */
                          unsigned int   AMXEXT:1;      /*              */
                          unsigned int   AMX   :3;      /*              */
                          unsigned int   RFSH  :1;      /*              */
                          unsigned int   RMODE :1;      /*              */
                          unsigned int   EDOMODE:1;     /*              */
                          }          BIT;               /*              */
                   }            MCR;                    /*              */
             union {                                    /*  PCR         */
                   unsigned short    WORD;              /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short A5PCW :2;      /*              */
                          unsigned short A6PCW :2;      /*              */
                          unsigned short A5TED :3;      /*              */
                          unsigned short A6TDE :3;      /*              */
                          unsigned short A5TEH :3;      /*              */
                          unsigned short A6TEH :3;      /*              */
                          }          BIT;               /*              */
                   }            PCR;                    /*              */
               char             wk2 [2];                /*              */
             union {                                    /*  RTCSR       */
                   unsigned short    WORD;              /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short CMF   :1;      /*              */
                          unsigned short CMIE  :1;      /*              */
                          unsigned short CKS   :3;      /*              */
                          unsigned short OVF   :1;      /*              */
                          unsigned short OVIE  :1;      /*              */
                          unsigned short LMTS  :1;      /*              */
                          }          BIT;               /*              */
                   }            RTCSR;                  /*              */
               char             wk3 [2];                /*              */
             unsigned short     RTCNT;                  /*              */
               char             wk4 [2];                /*              */
             unsigned short     RTCOR;                  /*              */
               char             wk5 [2];                /*              */
             unsigned short     RFCR;                   /*              */
};                                                      /*              */
struct st_cpg {                                         /* struct CPG   */
             union {                                    /*  FRQCR       */
                   unsigned short    WORD;              /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short       :4;      /*              */
                          unsigned short CKOEN :1;      /*              */
                          unsigned short PLL1EN:1;      /*              */
                          unsigned short PLL2EN:1;      /*              */
                          unsigned short IFC   :3;      /*              */
                          unsigned short BFC   :3;      /*              */
                          unsigned short PFC   :3;      /*              */
                          }          BIT;               /*              */
                   }           FRQCR;                   /*              */
               char             wk1 [2];                /*              */
             union {                                    /*  STBCR       */
                   unsigned char     BYTE;              /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char STBY  :1;       /*              */
                          unsigned char PHZ   :1;       /*              */
                          unsigned char PPU   :1;       /*              */
                          unsigned char MSTP4 :1;       /*              */
                          unsigned char MSTP3 :1;       /*              */
                          unsigned char MSTP2 :1;       /*              */
                          unsigned char MSTP1 :1;       /*              */
                          unsigned char MSTP0 :1;       /*              */
                          }          BIT;               /*              */
                   }           STBCR;                   /*              */
             char              wk2[3];                  /*              */
             unsigned short    WTCNT;                   /*  WTCNT       */
             char              wk3[2];                  /*              */
             unsigned short    WTCSR;                   /*  WTCSR       */
             char              wk4[2];                  /*              */
             union {                                    /*  STBCR2      */
                   unsigned char     BYTE;              /*  Byte Access */
                   struct {                             /*  Bit  Access */
                          unsigned char DSLP  :1;       /*              */
                          }          BIT;               /*              */
                   }           STBCR2;                  /*              */
};                                                      /*              */
struct st_mmu {                                         /* struct MMU   */
              unsigned int     PTEH  ;                  /* PTEH         */
              unsigned int     PTEL  ;                  /* PTEL         */
              unsigned int     TTB   ;                  /* TTB          */
              unsigned int     TEA   ;                  /* TEA          */
             union {                                    /*  MMUCR       */
                   unsigned int       LONG;             /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int LRUI:6;          /*    LRUI      */
                          unsigned int     :2;          /*              */
                          unsigned int URB :6;          /*    URB       */
                          unsigned int     :2;          /*              */
                          unsigned int URC :6;          /*    URC       */
                          unsigned int SQMD:1;          /*    SQMD      */
                          unsigned int SV  :1;          /*    SV        */
                          unsigned int     :5;          /*              */
                          unsigned int TI  :1;          /*    TI        */
                          unsigned int     :1;          /*              */
                          unsigned int AT  :1;          /*    AT        */
                          }          BIT;               /*              */
                   }           MMUCR ;                  /* MMUCR        */
              char             wk[32];                  /*              */
              unsigned int     PTEA  ;                  /* PTEA         */
};                                                      /*              */
struct st_cache {                                       /* struct CACHE */
             union {                                    /*  STBCR       */
                   unsigned int       LONG;             /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int    :16;          /*              */
                          unsigned int IIX:1;           /*    IIX       */
                          unsigned int    :3;           /*              */
                          unsigned int ICI:1;           /*    ICI       */
                          unsigned int    :2;           /*              */
                          unsigned int ICE:1;           /*    ICE       */
                          unsigned int OIX:1;           /*    OIX       */
                          unsigned int    :1;           /*              */
                          unsigned int ORA:1;           /*    ORA       */
                          unsigned int    :1;           /*              */
                          unsigned int OCI:1;           /*    OCI       */
                          unsigned int CB :1;           /*    CB        */
                          unsigned int WT :1;           /*    WT        */
                          unsigned int OCE:1;           /*    OCE       */
                          }          BIT;               /*              */
                   }           CCR  ;                   /*              */
              char             wk[24];                  /*              */
              unsigned int     QACR0 ;                  /* QACR0        */
              unsigned int     QACR1 ;                  /* QACR1        */
};                                                      /*              */
struct st_dmac {                                        /* struct DMAC  */
               union {                                  /* DMAOR        */
                     unsigned int    LONG;              /*  Long Access */
                     struct {                           /*  Bit  Access */
                            unsigned int       :16;     /*              */
                            unsigned int   DDT :1;      /*    DDT       */
                            unsigned int       :5;      /*              */
                            unsigned int   PR  :2;      /*    PR        */
                            unsigned int       :5;      /*              */
                            unsigned int   AE  :1;      /*    AE        */
                            unsigned int   NMIF:1;      /*    NMIF      */
                            unsigned int   DME :1;      /*    DME       */
                            }        BIT;               /*              */
                     }          DMAOR;                  /*              */
};                                                      /*              */
struct st_dmac0 {                                       /* struct DMAC0 */
                void           *SAR;                    /* SAR          */
                void           *DAR;                    /* DAR          */
                unsigned int    DMATCR;                 /* DMATCR       */
                union {                                 /* CHCR         */
                      unsigned int   LONG;              /*  Long Access */
                      struct {                          /*  Bit  Access */
                             unsigned int  SSA: 3;      /*              */
                             unsigned int  STC: 1;      /*              */
                             unsigned int  DSA: 3;      /*              */
                             unsigned int  DTC: 1;      /*              */
                             unsigned int     : 4;      /*              */
                             unsigned int  DS : 1;      /*              */
                             unsigned int  RL : 1;      /*              */
                             unsigned int   AM: 1;      /*    AM        */
                             unsigned int   AL: 1;      /*    AL        */
                             unsigned int   DM: 2;      /*    DM        */
                             unsigned int   SM: 2;      /*    SM        */
                             unsigned int   RS: 4;      /*    RS        */
                             unsigned int   TM: 1;      /*    TM        */
                             unsigned int   TS: 3;      /*    TS        */
                             unsigned int     : 1;      /*              */
                             unsigned int   IE: 1;      /*    IE        */
                             unsigned int   TE: 1;      /*    TE        */
                             unsigned int   DE: 1;      /*    DE        */
                             }       BIT;               /*              */
                      }         CHCR;                   /*              */
};                                                      /*              */
struct st_port {                                        /* struct PORT  */
             union {                                    /*  PORT        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int   PB15PUP:1;     /*              */
                          unsigned int   PB15IO :1;     /*              */
                          unsigned int   PB14PUP:1;     /*              */
                          unsigned int   PB14IO :1;     /*              */
                          unsigned int   PB13PUP:1;     /*              */
                          unsigned int   PB13IO :1;     /*              */
                          unsigned int   PB12PUP:1;     /*              */
                          unsigned int   PB12IO :1;     /*              */
                          unsigned int   PB11PUP:1;     /*              */
                          unsigned int   PB11IO :1;     /*              */
                          unsigned int   PB10PUP:1;     /*              */
                          unsigned int   PB10IO :1;     /*              */
                          unsigned int   PB9PUP:1;      /*              */
                          unsigned int   PB9IO :1;      /*              */
                          unsigned int   PB8PUP:1;      /*              */
                          unsigned int   PB8IO :1;      /*              */
                          unsigned int   PB7PUP:1;      /*              */
                          unsigned int   PB7IO :1;      /*              */
                          unsigned int   PB6PUP:1;      /*              */
                          unsigned int   PB6IO :1;      /*              */
                          unsigned int   PB5PUP:1;      /*              */
                          unsigned int   PB5IO :1;      /*              */
                          unsigned int   PB4PUP:1;      /*              */
                          unsigned int   PB4IO :1;      /*              */
                          unsigned int   PB3PUP:1;      /*              */
                          unsigned int   PB3IO :1;      /*              */
                          unsigned int   PB2PUP:1;      /*              */
                          unsigned int   PB2IO :1;      /*              */
                          unsigned int   PB1PUP:1;      /*              */
                          unsigned int   PB1IO :1;      /*              */
                          unsigned int   PB0PUP:1;      /*              */
                          unsigned int   PB0IO :1;      /*              */
                          }          BIT;               /*              */
                   }         PCTRA;                     /*              */
             union {                                    /*              */
                   unsigned short   WORD;               /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short P15DT  :1;     /*              */
                          unsigned short P14DT  :1;     /*              */
                          unsigned short P13DT  :1;     /*              */
                          unsigned short P12DT  :1;     /*              */
                          unsigned short P11DT  :1;     /*              */
                          unsigned short P10DT  :1;     /*              */
                          unsigned short P9DT   :1;     /*              */
                          unsigned short P8DT   :1;     /*              */
                          unsigned short P7DT   :1;     /*              */
                          unsigned short P6DT   :1;     /*              */
                          unsigned short P5DT   :1;     /*              */
                          unsigned short P4DT   :1;     /*              */
                          unsigned short P3DT   :1;     /*              */
                          unsigned short P2DT   :1;     /*              */
                          unsigned short P1DT   :1;     /*              */
                          unsigned short P0DT   :1;     /*              */
                          }          BIT;               /*              */
                   }         PDTRA;                     /*              */
              char             wk1[14];                 /*              */
             union {                                    /*  PORT        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int         :24;     /*              */
                          unsigned int   PB19PUP:1;     /*              */
                          unsigned int   PB19IO :1;     /*              */
                          unsigned int   PB18PUP:1;     /*              */
                          unsigned int   PB18IO :1;     /*              */
                          unsigned int   PB17PUP:1;     /*              */
                          unsigned int   PB17IO :1;     /*              */
                          unsigned int   PB16PUP:1;     /*              */
                          unsigned int   PB16IO :1;     /*              */
                          }          BIT;               /*              */
                   }         PCTRB;                     /*              */
             union {                                    /*              */
                   unsigned short   WORD;               /*  Word Access */
                   struct {                             /*  Bit  Access */
                          unsigned short       :12;     /*              */
                          unsigned short P19DT  :1;     /*              */
                          unsigned short P18DT  :1;     /*              */
                          unsigned short P17DT  :1;     /*              */
                          unsigned short P16DT  :1;     /*              */
                          }          BIT;               /*              */
                   }         PDTRB;                     /*              */
              char             wk2[2];                  /*              */
             union {                                    /*  PORT        */
                   unsigned int      LONG;              /*  Long Access */
                   struct {                             /*  Bit  Access */
                          unsigned int  PTIREN15:1;     /*              */
                          unsigned int  PTIREN14:1;     /*              */
                          unsigned int  PTIREN13:1;     /*              */
                          unsigned int  PTIREN12:1;     /*              */
                          unsigned int  PTIREN11:1;     /*              */
                          unsigned int  PTIREN10:1;     /*              */
                          unsigned int  PTIREN9 :1;     /*              */
                          unsigned int  PTIREN8 :1;     /*              */
                          unsigned int  PTIREN7 :1;     /*              */
                          unsigned int  PTIREN6 :1;     /*              */
                          unsigned int  PTIREN5 :1;     /*              */
                          unsigned int  PTIREN4 :1;     /*              */
                          unsigned int  PTIREN3 :1;     /*              */
                          unsigned int  PTIREN2 :1;     /*              */
                          unsigned int  PTIREN1 :1;     /*              */
                          unsigned int  PTIREN0 :1;     /*              */
                          }          BIT;               /*              */
                   }        GPIOIC;                     /*              */
};                                                      /*              */

#define SCI   (*(volatile struct st_sci   *)0xFFE00000) /* SCI   Address*/
#define SCIF  (*(volatile struct st_scif  *)0xFFE80000) /* SCIF  Address*/
#define TMU   (*(volatile struct st_tmu   *)0xFFD80000) /* TMU   Address*/
#define TMU0  (*(volatile struct st_tmu0  *)0xFFD80008) /* TMU0  Address*/
#define TMU1  (*(volatile struct st_tmu0  *)0xFFD80014) /* TMU1  Address*/
#define TMU2  (*(volatile struct st_tmu2  *)0xFFD80020) /* TMU2  Address*/
#define RTC   (*(volatile struct st_rtc   *)0xFFC80000) /* RTC   Address*/
#define INTC  (*(volatile struct st_intc  *)0xFFD00000) /* INTC  Address*/
#define BSC   (*(volatile struct st_bsc   *)0xFF800000) /* BSC   Address*/
#define CPG   (*(volatile struct st_cpg   *)0xFFC00000) /* CPG   Address*/
#define MMU   (*(volatile struct st_mmu   *)0xFF000000) /* MMU   Address*/
#define CACHE (*(volatile struct st_cache *)0xFF00001C) /* CACHE Address*/
#define DMAC  (*(volatile struct st_dmac  *)0xFFA00040) /* DMAC  Address*/
#define DMAC0 (*(volatile struct st_dmac0 *)0xFFA00000) /* DMAC0 Address*/
#define DMAC1 (*(volatile struct st_dmac0 *)0xFFA00010) /* DMAC1 Address*/
#define DMAC2 (*(volatile struct st_dmac0 *)0xFFA00020) /* DMAC2 Address*/
#define DMAC3 (*(volatile struct st_dmac0 *)0xFFA00030) /* DMAC3 Address*/
#define PORT  (*(volatile struct st_port  *)0xFF80002C) /* PORT  Address*/
#define EXP   (*(volatile struct st_exp   *)0xFF000020) /* TRA   Address*/
