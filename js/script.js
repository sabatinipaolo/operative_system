let processo = [
  {id: 0, istanteDiArrivo: 2, tempoDiEsecuzione: 4, tempoRimanente: 4},
  {id: 1, istanteDiArrivo: 0, tempoDiEsecuzione: 2, tempoRimanente: 2},
  {id: 2, istanteDiArrivo: 1, tempoDiEsecuzione: 3, tempoRimanente: 3},
  {id: 3, istanteDiArrivo: 3, tempoDiEsecuzione: 2, tempoRimanente: 2},
  {id: 4, istanteDiArrivo: 4, tempoDiEsecuzione: 3, tempoRimanente: 3}
];


function nProcessi() {
  let n = parseInt(prompt("Inserisci il numero di processi: "));
  return n;
}

function inizializza(processi, numeroDiProcessi) {
  for (let i = 0; i < numeroDiProcessi; i++) {
      processi[i].id = i;
      console.log(`\nProcesso ${processi[i].id}:`);
      processi[i].istanteDiArrivo = parseInt(prompt("-istante di arrivo: "));
      processi[i].tempoDiEsecuzione = parseInt(prompt("-tempo di esecuzione: "));
      console.log(`Processo ${processi[i].id}: Istante di arrivo: ${processi[i].istanteDiArrivo} Tempo di esecuzione: ${processi[i].tempoDiEsecuzione}`);
      processi[i].tempoRimanente = processi[i].tempoDiEsecuzione;
  }
}

function ordinamentoProcessiId(processi, processiLength) {
  for (let j = 0; j < processiLength; j++) {
      for (let i = 0; i < processiLength - (j + 1); i++) {
          if (processi[i].id > processi[i + 1].id) {
            let swap={...processo}
              swap = processi[i];
              processi[i] = processi[i + 1];
              processi[i + 1] = swap;
          }
      }
  }
}

function ordinamentoProcessiPerTempoDiEsecuzione(processi, processiLength) {
  for (let j = 0; j < processiLength; j++) {
      for (let i = 0; i < processiLength; i++) {
          if (processi[i].tempoDiEsecuzione > processi[i + 1].tempoDiEsecuzione) {
            let swap={...processo}
            swap = processi[i];
            processi[i] = processi[i + 1];
            processi[i + 1] = swap;
          }
      }
  }
  console.log(coda);
}


let numeroDiProcessi = 5


function ordinamentoProcessi(processi, processiLength) {
    // implementazione dell'ordinamento dei processi
    for (let j = 0; j < processiLength; j++) {
      for (let i = 0; i < processiLength - (j + 1); i++) {
          if (processi[i].istanteDiArrivo > processi[i + 1].istanteDiArrivo) {
              let swap={...processo}
              swap = processi[i];
              processi[i] = processi[i + 1];
              processi[i + 1] = swap;
          }
      }
  }
}

function trovaTempoTotale(processi, numeroDiProcessi) {
    // implementazione del calcolo del tempo totale
  let tempoTotale = 0;
  for (let i = 0; i < numeroDiProcessi; i++) {
      tempoTotale += processi[i].tempoDiEsecuzione;
  }
  return tempoTotale;
}

function trovaAttesaSingola(attesaCoda, processi, processiLength) {
  attesaCoda[0] = 0;
  let tempoDiEsecuzioneTotale = 0;
  for (let i = 1; i < processiLength; i++) {
      tempoDiEsecuzioneTotale += processi[i - 1].tempoDiEsecuzione;
      attesaCoda[i] = tempoDiEsecuzioneTotale - processi[i].istanteDiArrivo;
  }
}

function trovaAttesaMedia(attesaCoda, processiLength) {
    // implementazione del calcolo dell'attesa media
    let attesaMedia = 0;
    for (let i = 1; i < processiLength; i++) {
        attesaMedia += attesaCoda[i];
    }
    attesaMedia /= processiLength;
    return attesaMedia;
}

function trovaCompletamento(processi, attesaCoda, processiLength) {
    // implementazione del calcolo del completamento
  let tempoCompletamento = 0;
  for (let i = 1; i < processiLength; i++) {
      tempoCompletamento += attesaCoda[i] + processi[i].tempoDiEsecuzione;
  }
  return tempoCompletamento;
}

function trovaCompletamentoMedia(completamentoTotale, processiLength) {
    // implementazione del calcolo del completamento medio
  let completamentoMedia = completamentoTotale / processiLength;
  return completamentoMedia;
}

function printProcessi(processi, processiLength) {
    // implementazione della stampa dei processi
  for (let i = 0; i < processiLength; i++) {
      console.log(`processo ${processi[i].id}\n   -istante di arrivo: ${processi[i].istanteDiArrivo}\n   -tempo di esecuzione: ${processi[i].tempoDiEsecuzione}`);
  }
  console.log("\n");
}

function printSequenzaTemporale(processi, attesaCoda, processiLength) {
    // implementazione della stampa della sequenza temporale
  let istante = 0;
  for (let i = 0; i < processiLength; i++) {
      for (let j = 0; j < processi[i].tempoDiEsecuzione; j++) {
          console.log("|" + processi[i].id + "|");
          istante++;
      }
  }
  istante = 0;
  const body = document.body
  for (let i = 0; i < processiLength; i++) {
      for (let j = 0; j < processi[i].tempoDiEsecuzione; j++) {
          body.innerHTML += "|" + processi[i].id + "|";
          istante++;
      }
  }
}

function sjf(processi, tempoTotale) {
  let prcInArrivo = 0; const prcInArrivoHtml = [];
  let prcInEsecuzione = processi[0].id;
  let coda = [];
  Object.assign(coda, processo)
  let sequenzaTemporale = [];
  const codaHtml = document.getElementById("coda")
  const prcInEsecuzioneHtml = document.getElementById("prcInEsecuzione")

  for (let i = 0; i < tempoTotale; i++) {
    setTimeout(function (){
      if (processi[prcInArrivo].istanteDiArrivo === i) {
        coda.push(processi[prcInArrivo]);
        prcInArrivoHtml.push ("<div class='processoArrivato'>" + coda[coda.length-1].id + "</div>")
        codaHtml.innerHTML += prcInArrivoHtml
        prcInArrivo++;
        console.log(coda)
      }
      if (processi[prcInEsecuzione].tempoRimanente === 0) {    
        coda.shift();
        ordinamentoProcessiPerTempoDiEsecuzione(coda, coda.length-1);
        console.log(`esce ${prcInEsecuzione} a ${i} ed entra ${coda[0].id}`);
        prcInEsecuzione = coda[0].id;  
        prcInEsecuzioneHtml.innerHTML = prcInArrivoHtml[0];  
        prcInArrivoHtml.shift();    
        console.log(prcInArrivoHtml)
      }

      processi[prcInEsecuzione].tempoRimanente--;
      sequenzaTemporale[i] = prcInEsecuzione;
    }, 1000*i);

  }
}

ordinamentoProcessi(processo);
let tempoTotale = trovaTempoTotale(processo, numeroDiProcessi);
let attesa = [];
  attesa[0] = 0;
  let tempoDiEsecuzioneTotale = 0;
  for (let i = 1; i < numeroDiProcessi; i++) {
      tempoDiEsecuzioneTotale += processo[i - 1].tempoDiEsecuzione;
      attesa[i] = tempoDiEsecuzioneTotale - processo[i].istanteDiArrivo;
  }
let attesaMedia = trovaAttesaMedia(attesa, numeroDiProcessi);
let tempoCompletamento = trovaCompletamento(processo, attesa, numeroDiProcessi);
let completamentoMedia = trovaCompletamentoMedia(tempoCompletamento, numeroDiProcessi);

console.log("attesa media:", attesaMedia);
console.log("media tempo di completamento:", completamentoMedia);
printProcessi(processo, numeroDiProcessi);
printSequenzaTemporale(processo, attesa, numeroDiProcessi);
sjf(processo, tempoTotale)