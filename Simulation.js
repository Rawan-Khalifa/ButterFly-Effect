function calc() {
      var   k = parseFloat(document.getElementById('k').value);
      var   x = parseFloat(document.getElementById('x').value);
      document.getElementById("Restoring").innerHTML = -k * x ;
      }
calc(  k ,x );

function calc2() {
      var   T = parseFloat(document.getElementById('T').value);
      var   B = parseFloat(document.getElementById('B').value);
      document.getElementById("Fnet").innerHTML = T - B ;

        if ( T-B < T) {
    alert("There is no Torque");
    return false;
  }

}

calc2(B, Y);

function calc3() {
      var   W = parseFloat(document.getElementById('W').value);
      var   Q = parseFloat(document.getElementById('Q').value);
      var   A = parseFloat(document.getElementById('A').value);
      var   S = parseFloat(document.getElementById('S').value);
      document.getElementById("Angular").innerHTML = (W/Q + A/S) * -1 ;
      }
calc3();
function calc4() {
      var   D = parseFloat(document.getElementById('D').value);
      var   F = parseFloat(document.getElementById('F').value);
      document.getElementById("output").innerHTML = D/F ;
      }
calc4( D, F);
function calc5() {
      var   G = parseFloat(document.getElementById('G').value);
      var   H = parseFloat(document.getElementById('H').value);
      document.getElementById("acceleration").innerHTML = G*H ;
      }
calc5( G, H);

function calc6() {
      var   J = parseFloat(document.getElementById('J').value);
      var   L = parseFloat(document.getElementById('L').value);
      var   N = parseFloat(document.getElementById('N').value);
      document.getElementById("voltage").innerHTML = L* Math.sin(J*N) ;
      }
calc6();
function calc7() {
      var   M = parseFloat(document.getElementById('M').value);
      var   Z = parseFloat(document.getElementById('Z').value);
      document.getElementById("current").innerHTML = M/Z ;
      }
calc7();
function calc8() {
  var   HH = parseFloat(document.getElementById('HH').value);
  var   HS = parseFloat(document.getElementById('HS').value);
      document.getElementById("Power").innerHTML = HH*HS ;
      }
calc8();
