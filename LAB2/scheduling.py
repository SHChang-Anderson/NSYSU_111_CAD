
MultiplexorCycle = 2
AdderCycle = 1
f = open("Scheduling_outcome.txt","w")
f.close

class stater:  #Store the current available number of ALUs and current stage
    adder : int
    mul   : int
    statenow : int

class thisline: # Store operators and operation numbers
    op  : int
    op1 : int
    op2 : int 
    res : int
    done : int 
    def __init__(self,op ,op1,op2,res,done):
        self.op = op
        self.op1 = op1
        self.op2 = op2
        self.res = res
        self.done = done
        

class op : # Record different operation numbers' state
    rdy : int 
    counter : int # Used to count down whether the operation is completed
    adderr  : int # Used to count down whether the adder is avaliable now
    mull    : int # Used to count down whether the multiplexor is avaliable now
    def __init__(self,rdy,counter,adderr,mull):
        self.rdy = rdy
        self.counter = counter
        self.adderr = adderr
        self.mull = mull





rdyline = []
classer = []
oper = []
nowstate = stater
path = []
haveedit = []



for i in range (200): # initialize operation numbers' state
    oper.append(op(0,0,0,0))




def readfile():
    val = input("intput a file name")
    f = open(val,"r")
    f.readline()
    temperint = []
    
    while(1):

        lines = f.readline()
        if not lines:

            break

        temper = lines.split(' ')

        for i in range (4):

            temperint.append ( int(temper[i]))

        classer.append(thisline(temperint[0],temperint[1],temperint[2],temperint[3],0))

        temperint.clear()

    lines = f.readline()

    temper = lines.split(' ')
    


def output():
    ff = open("Scheduling_outcome.txt","a")
    max = 0
    for i in range(len(rdyline)): # find the longest critical path
        if(path[classer[rdyline[i]].res] >= max):
            max = path[classer[rdyline[i]].res]
            falger = rdyline[i]

    if(classer[falger].op == 1): # Adder
            if(stater.adder!=0):
                stater.adder=stater.adder-1 # Adder using
                stringout = "state : " + str(nowstate.statenow) +" v" + str(classer[falger].res) + " v" + str(classer[falger].op1) + " v" + str(classer[falger].op2)
                print(stringout)
                ff.write(stringout + "\n")
                oper[classer[falger].res].counter = AdderCycle # Check whether the operation number has finished computing
                oper[classer[falger].res].rdy = 0
                oper[classer[falger].res].adderr = AdderCycle # Check whether the adder has finished computing  
                haveedit.append(falger) # already output 

    else:   #Multiplexor
            if(stater.mul!=0):
                stater.mul=stater.mul-1 # Multiplexor using
                stringout = "state : " + str(nowstate.statenow) +" v" +str(classer[falger].res) + " v" + str(classer[falger].op1) + " v" + str(classer[falger].op2)
                print(stringout)
                ff.write(stringout + "\n")
                oper[classer[falger].res].counter = MultiplexorCycle # Check whether the operation number has finished computing
                oper[classer[falger].res].rdy = 0
                oper[classer[falger].res].mull = MultiplexorCycle # Check whether the Multiplexor has finished computing  
                haveedit.append(falger)  # already output 


    for xx in range(len(haveedit)): # Remove completed computations
        classer[haveedit[xx]].done = 1
    
    haveedit.clear()
    ff.close
    return
    
    
        





def scheduling():
    

    # ----------------↓ Set the limitation of ALUs ↓---------------------------------------------

    textin = input("\n limitation of multiplexor...")

    nowstate.mul = int(textin) 

    textin = input("\n limitation of Adder...")

    nowstate.adder = int(textin) 

    f = open("Scheduling_outcome.txt","a")
    f.write("*****************************\n")
    f.write("*    Resource Constraint    *\n")
    f.write("*                           *\n")
    f.write("*     Mult Constraint:%1d     *\n" % (nowstate.mul))
    f.write("*     Add  Constraint:%1d     *\n" % (nowstate.adder))
    f.write("*                           *\n")
    f.write("*****************************\n")

    f.close

    nowstate.statenow = 1

    flagg1 = 0
    flagg2 = 0

    # ----------------↑ Set the limitation of ALUs ↑---------------------------------------------


    



    # ----------------↓ computing the critical path length ↓---------------------------------------------
    path.clear()
    for i in range (200):
            path.append(0) # initialize the path number

    counter = len(classer)-1
    while(1):
        for i in range(counter + 1 , len(classer)):
            if(classer[counter].res == classer[i].op1 or classer[counter].res == classer[i].op2):
                if(classer[counter].op == 1):
                    if(path[classer[i].res] + AdderCycle > path[classer[counter].res]):
                        path[classer[counter].res] = path[classer[i].res] + AdderCycle
            if(classer[counter].res == classer[i].op1 or classer[counter].res == classer[i].op2):
                if(classer[counter].op == 2):
                   if(path[classer[i].res] + MultiplexorCycle > path[classer[counter].res]):
                        path[classer[counter].res] = path[classer[i].res] + MultiplexorCycle
        counter = counter - 1
        if(counter == -1):
            break
    # ----------------↑ computing the critical path length ↑---------------------------------------------




    # -------------------------- ↓ checking the dependencies and add to the ready list ↓ -------------------------------
    for zz in range (2000): # Each iteration represents a stage
        rdyline.clear()

        for i in range (len(classer)):
            
            if(classer[i].done != 1): #haven't output yet

                if(classer[i].op == 1): # Adder

                    if(stater.adder!=0):

                        for j in range (0 , i): # Check for dependencies

                            if((classer[i].op1==classer[j].res) ):
                                flagg1 = classer[j].res

                            if((classer[i].op2==classer[j].res) ):
                                flagg2  = classer[j].res
                        if(flagg1==0 and flagg2==0): # No dependencies
                            rdyline.append(i) # add to the ready list 

                            

                        else:
                            
                            if(((oper[flagg1].rdy==1) and (oper[flagg2].rdy==1)) or ( (flagg1 == 0) 
                            and (oper[flagg2].rdy==1) ) or ((oper[flagg1].rdy==1) and (flagg2 == 0))): # The dependent data is ready
                                
                                rdyline.append(i) # add to the ready list 
            
                            
                            flagg1 = 0
                            flagg2 = 0


                else:   #Multiplexor

                    if(stater.mul!=0):

                        for j in range (0 , i):

                            if((classer[i].op1==classer[j].res) ):
                                flagg1 = classer[j].res
                                
                            if((classer[i].op2==classer[j].res) ):
                                flagg2  = classer[j].res

                        if(flagg1==0 and flagg2==0): # No dependencies
                            

                            rdyline.append(i) # add to the ready list 
                            
                        
                        else:

                            if(((oper[flagg1].rdy==1) and (oper[flagg2].rdy==1)) or ( (flagg1 == 0) 
                            and (oper[flagg2].rdy==1) ) or ((oper[flagg1].rdy==1) and (flagg2 == 0))): # The dependent data is ready
                                
                                rdyline.append(i) # add to the ready list 

                            flagg1 = 0
                            flagg2 = 0

        if(len(rdyline) != 0 ): # there are still something in the ready list 
            output()
            zz = zz -1 
        # --------------------------↑ checking the dependencies and add to the ready list ↑-------------------------------



        # ---------------------------↓ Update the state ↓---------------------------------------------
        
        else: # there are nothing in the ready list update!!
            stater.statenow = stater.statenow + 1 
            
            for x in range(200): # Update the ALU and operation numbers' states
                if(oper[x].counter!=0):
                    oper[x].counter = oper[x].counter - 1
                    if(oper[x].counter == 0): 
                        oper[x].rdy = 1
                
                if(oper[x].adderr!=0):
                    oper[x].adderr = oper[x].adderr - 1
                    if(oper[x].adderr == 0):
                        stater.adder = stater.adder + 1
                if(oper[x].mull!=0):
                    oper[x].mull = oper[x].mull - 1
                    if(oper[x].mull == 0):
                        stater.mul = stater.mul + 1

        # ---------------------------↑ Update the state ↑---------------------------------------------








def main():
    readfile()
    scheduling()
    

if __name__ == "__main__":
    main()
