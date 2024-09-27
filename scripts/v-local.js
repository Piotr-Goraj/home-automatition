const { execSync } = require('child_process');
const args = process.argv.slice(2);

// Znajdujemy argument '-m' i wyciągamy wiadomość
let commitMessage = null;

for (let i = 0; i < args.length; i++) {
  if (args[i] === '-m' && i + 1 < args.length) {
    commitMessage = args[i + 1].replace(/['"]/g, ''); // Usuwanie cudzysłowów
    break;
  }
}

if (!commitMessage) {
  console.error('Error: Commit message is required.');
  process.exit(1);
}

// Znajdujemy submodule (jeśli został podany)
const submodule = args.find((arg) => !arg.startsWith('-m')) || 'all';

try {
  if (submodule === 'all') {
    console.log('Committing all submodules and main repo...');
    execSync(`git commit -am "${commitMessage}"`, { stdio: 'inherit' });
    execSync(`git submodule foreach 'git commit -am "${commitMessage}"'`, {
      stdio: 'inherit',
    });
  } else {
    console.log(`Committing to submodule: ${submodule}`);
    execSync(`git commit -am "${commitMessage}"`, { stdio: 'inherit' });
    execSync(`cd ${submodule} && git commit -am "${commitMessage}"`, {
      stdio: 'inherit',
    });
  }
} catch (error) {
  console.error(`Error committing: ${error.message}`);
}
