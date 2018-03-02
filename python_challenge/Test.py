#coding:utf-8
import time
import json
from Game import   GOL, State

if __name__=="__main__":
    with open("test.json",'r') as test:
        test=json.load(test)
        #Test 1
        print ("***** Test 1 *****")
        glider=test['Initial']['a']
        my_game=GOL(State(glider,x=2,y=3,width=20, height=10))
        print ("Generation 1")
        my_game.step(1)
        print (str(test["Gen 1"]['a'])==str(my_game.display()))
        assert str(test["Gen 1"]['a'])==str(my_game.display())
        
        print ("Generation 2")
        my_game.step(1)
        print (str(test["Gen 2"]['a'])==str(my_game.display()))
        assert str(test["Gen 2"]['a'])==str(my_game.display())        
        
        print ("\n\n***** Test 2 *****")
        glider=test['Initial']['b']
        my_game=GOL(State(glider,x=2,y=3,width=20, height=10))
        print ("Generation 1")
        my_game.step(1)
        print (str(test["Gen 1"]['b'])==str(my_game.display()))
        assert str(test["Gen 1"]['b'])==str(my_game.display())
        
        print ("Generation 2")
        my_game.step(1)
        print (str(test["Gen 2"]['b'])==str(my_game.display()))
        assert str(test["Gen 2"]['b'])==str(my_game.display())        