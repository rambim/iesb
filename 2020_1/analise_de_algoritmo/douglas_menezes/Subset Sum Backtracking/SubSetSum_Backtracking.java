import java.util.Stack;

class SubSet{
  int set[];
  int sum;
  
  Stack<Integer> solutionSet;
  boolean hasSolution;
  
  SubSet(int set[], int sum){
      this.set = set;
      this.sum = sum;
      this.solutionSet = new Stack<>();
      hasSolution = false;
  }
  
  public boolean solve(int s, int idx){   
    if(s>sum)
        return false;
 
    if(s==sum){
        hasSolution = true;
 
        displaySolutionSet();
 
        return false;
    }
        
    for(int i=idx; i<set.length; i++){
        solutionSet.push(set[i]);
 
        if(solve(s+set[i],i+1)){
            return true;
        }
 
        solutionSet.pop();
    }
    
    return false;
  }
  
  private void displaySolutionSet(){
    for (Integer item: solutionSet){
      System.out.print(item+" ");
    }
        System.out.println();
    }
    
    
}
 