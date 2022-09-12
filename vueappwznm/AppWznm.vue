<template>
	<v-app>
		<v-main>
			<!-- srefIxVSge prop for CrdWznmStart, others for SessWznm -->
			<component
				v-bind:is="content"
				v-on:login="handleLogin"
				v-on:logout="handleLogout"
				ref="content"
				:srefIxVSge_initial=srefIxVSge
				:scrJrefSess=scrJrefSess
				:scrJrefCrdnav=scrJrefCrdnav
				:srefCrd_initial=srefCrd
				:scrJrefCrd_initial=scrJrefCrd
			/>
		</v-main>
	</v-app>
</template>

<script>
	import Wznm from './scripts/Wznm';

	import CrdWznmStart from './components/CrdWznmStart/CrdWznmStart';
	import SessWznm from './components/SessWznm';

	export default {
		name: 'AppWznm',

		components: {
			CrdWznmStart,
			SessWznm
		},

		beforeMount() {
			document.title = Wznm.title + " v" + Wznm.version;

			// possible keys: scrJrefSess, scrJrefCrdnav, srefCrd, scrJrefCrd
			const params = new URLSearchParams(window.location.search);
			//params.forEach(function(value, key) {console.log(key + ": " + value)});

			this.childNotParent = params.has("scrJrefSess");

			if (!this.childNotParent) this.content = "CrdWznmStart";
			else {
				this.scrJrefSess = params.get("scrJrefSess");
				this.scrJrefCrdnav = params.get("scrJrefCrdnav");

				this.srefCrd = params.get("srefCrd");
				this.scrJrefCrd = params.get("scrJrefCrd");

				this.content = "SessWznm";
			}
		},

		methods: {
			handleLogin(obj) {
				//console.log("AppWznm.handleLogin() received login event with scrJrefSess = " + scrJrefSess);

				this.scrJrefSess = obj.scrJrefSess;
				this.scrJrefCrdnav = obj.scrJrefCrdnav;

				this.srefCrd = "";
				this.scrJrefCrd = "";

				this.content = "SessWznm"
			},

			handleLogout() {
				if (!this.childNotParent) {
					this.srefIxVSge = "term";

					this.scrJrefSess = "";
					this.scrJrefCrdnav = "";

					this.srefCrd = "";
					this.scrJrefCrd = "";

					this.content = "CrdWznmStart"

				} else window.open("about:blank", "_self");
			}
		},

		data: () => ({
			childNotParent: false,	

			content: "",

			srefIxVSge: "idle",

			scrJrefSess: "",
			scrJrefCrdnav: "",

			srefCrd: "",
			scrJrefCrd: ""
		})
	};
</script>
